/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:49:58 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 20:01:33 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ft_time.h"
#include "mutex.h"
#include <stdio.h>
#include <unistd.h>

int	get_meals_eaten(t_philo *philo)
{
	int	meals_eaten;

	pthread_mutex_lock(&philo->meals_eaten.mutex);
	meals_eaten = philo->meals_eaten.value;
	pthread_mutex_unlock(&philo->meals_eaten.mutex);
	return (meals_eaten);
}

long	get_last_meal_value(t_lmutex *last_meal)
{
	long	last_meal_value;

	pthread_mutex_lock(&last_meal->mutex);
	last_meal_value = last_meal->value;
	pthread_mutex_unlock(&last_meal->mutex);
	return (last_meal_value * 1000);
}

int	print_dead_lock(t_philo *philo, t_data *data)
{
	set_value(&data->dead, 1);
	while (1)
	{
		if (mutex_get(philo->write))
		{
			printf("%ld %d %s\n", get_time_since_start(philo->args->start),
				philo->id, "died");
			break ;
		}
		usleep(700);
	}
	return (1);
}
