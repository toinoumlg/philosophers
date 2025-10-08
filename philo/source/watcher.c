/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 00:30:36 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ft_time.h"
#include "mutex.h"
#include <stdio.h>
#include <unistd.h>

long	get_last_meal_value(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->last_meal.mutex);
	last_meal = philo->last_meal.value;
	pthread_mutex_unlock(&philo->last_meal.mutex);
	return (last_meal);
}

void	print_dead_lock(t_philo *philo, t_data *data)
{
	int	start;

	start = get_time_since_start(philo->args->start);
	set_value(&data->dead, 1);
	while (1)
	{
		if (mutex_get(philo->write))
		{
			printf("%d %d %s\n", start, philo->id, "died");
			break ;
		}
		else
			usleep(600);
	}
}

int	check_for_death(t_data *data)
{
	int		i;
	long	start;

	i = 0;
	start = get_time_since_start(data->args.start);
	while (i < data->nbr_of_philo)
	{
		if (start - get_last_meal_value(&data->philos[i]) > data->args.tt_die)
		{
			print_dead_lock(&data->philos[i], data);
			return (1);
		}
		i++;
	}
	return (0);
}

int	get_meals_eaten(t_philo *philo)
{
	int	meals_eaten;

	pthread_mutex_lock(&philo->meals_eaten.mutex);
	meals_eaten = philo->meals_eaten.value;
	pthread_mutex_unlock(&philo->meals_eaten.mutex);
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
	set_value(&data->dead, 1);
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

	if (pthread_create(&watcher, NULL, watcher_routine, (void *)data))
		return ;
	pthread_join(watcher, NULL);
}
