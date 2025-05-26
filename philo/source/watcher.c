/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 19:01:03 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "print_lock.h"
#include <unistd.h>

void	check_for_death(t_data *data)
{
	int		i;
	size_t	last_meal;
	size_t	start;
	int		is_eating;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		pthread_mutex_lock(data->data_access);
		last_meal = data->philos[i].last_meal;
		is_eating = data->philos[i].is_eating;
		start = get_time_since_start(data->philos[i].start);
		pthread_mutex_unlock(data->data_access);
		if ((start - last_meal > data->tt_die) && !is_eating)
		{
			pthread_mutex_lock(data->data_access);
			data->dead_flag = 1;
			pthread_mutex_unlock(data->data_access);
			print_dead_lock(&data->philos[i]);
			return ;
		}
		i++;
	}
}

void	check_for_meals_goal(t_data *data)
{
	int	i;
	int	meals_eaten;

	i = 0;
	if (data->meals_goal < 0)
		return ;
	while (i < data->nbr_of_philo)
	{
		pthread_mutex_lock(data->data_access);
		meals_eaten = data->philos[i].meals_eaten;
		pthread_mutex_unlock(data->data_access);
		if (meals_eaten < data->meals_goal)
			break ;
		i++;
	}
	if (i == data->nbr_of_philo)
	{
		pthread_mutex_lock(data->data_access);
		data->meal_flag = 1;
		pthread_mutex_unlock(data->data_access);
	}
}

void	*start_watcher_routine(void *data_add)
{
	t_data	*data;

	data = (t_data *)data_add;
	usleep(data->tt_die * 1000);
	while (!data->meal_flag && !data->dead_flag)
	{
		check_for_death(data);
		check_for_meals_goal(data);
		usleep(1000);
	}
	return (NULL);
}

void	set_watcher(t_data *data)
{
	pthread_t	watcher;

	pthread_create(&watcher, NULL, start_watcher_routine, (void *)data);
	pthread_join(watcher, NULL);
}
