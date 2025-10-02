/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/02 19:28:33 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include "time.h"
#include <stdio.h>
#include <unistd.h>

long	get_last_meal_value(t_philo *philo)
{
	long	last_meal;

	while (is_taken(&philo->data_access))
		usleep(50);
	set_value(&philo->data_access, 1);
	last_meal = philo->last_meal;
	set_value(&philo->data_access, 0);
	return (last_meal);
}

int	is_eating(t_philo *philo)
{
	int	eating;

	while (is_taken(&philo->data_access))
		usleep(50);
	set_value(&philo->data_access, 1);
	eating = philo->is_eating;
	set_value(&philo->data_access, 0);
	return (eating);
}

int	check_for_death(t_data *data)
{
	int		i;
	long	start;

	i = 0;
	start = get_time_since_start(data->args.start);
	while (i < data->nbr_of_philo)
	{
		if ((start - get_last_meal_value(&data->philos[i]) > data->args.tt_die)
			&& !is_eating(&data->philos[i]))
		{
			print_lock(&data->philos[i], "died");
			set_value(&data->write, 1);
			set_value(&data->end, 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_meals_eaten(t_philo *philo)
{
	int	meals_eaten;

	while (is_taken(&philo->data_access))
		usleep(100);
	set_value(&philo->data_access, 1);
	meals_eaten = philo->meals_eaten;
	set_value(&philo->data_access, 0);
	return (meals_eaten);
}

int	check_for_meals_goal(t_data *data)
{
	int	i;

	i = 0;
	if (data->args.meals_goal == 0)
		return (0);
	while (i < data->nbr_of_philo)
	{
		if (get_meals_eaten(&data->philos[i]) < data->args.meals_goal)
			return (0);
		i++;
	}
	set_value(&data->write, 1);
	set_value(&data->end, 1);
	return (1);
}

void	*watcher_routine(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	while (1)
	{
		if (check_for_death(data))
			break ;
		if (check_for_meals_goal(data))
			break ;
		usleep(400);
	}
	return (NULL);
}

void	set_watcher(t_data *data)
{
	pthread_t	watcher;

	pthread_create(&watcher, NULL, watcher_routine, (void *)data);
	pthread_join(watcher, NULL);
}
