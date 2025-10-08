/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:55:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 00:34:13 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>
#include "mutex.h"

void	set_value_meal_eaten(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->value++;
	pthread_mutex_unlock(&mutex->mutex);
}

int	mutex_get(t_mutex *fork)
{
	pthread_mutex_lock(&fork->mutex);
	if (!fork->value)
	{
		fork->value = 1;
		pthread_mutex_unlock(&fork->mutex);
		return (1);
	}
	pthread_mutex_unlock(&fork->mutex);
	return (0);
}

void	set_value(t_mutex *mutex, int value)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->value = value;
	pthread_mutex_unlock(&mutex->mutex);
}

void set_value_last_meal(t_lmutex *mutex, long value)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->value = value;
	pthread_mutex_unlock(&mutex->mutex);
}

void	destroy_mutex(t_mutex *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
		pthread_mutex_destroy(&forks[i++].mutex);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
		pthread_mutex_init(&data->forks[i++].mutex, NULL);
	data->write.value = 0;
	data->dead.value = 0;
	pthread_mutex_init(&data->write.mutex, NULL);
	pthread_mutex_init(&data->dead.mutex, NULL);
}
