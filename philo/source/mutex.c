/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:55:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:13:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include <stdio.h>

void	set_value_meal_eaten(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->value++;
	pthread_mutex_unlock(&mutex->mutex);
}

void	set_value_last_meal(t_lmutex *mutex, long value)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->value = value;
	pthread_mutex_unlock(&mutex->mutex);
}

void	ft_mutex_destroy(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	while (i < data->nbr_of_philo)
	{
		if (!data->forks[i].init)
			pthread_mutex_destroy(&data->forks[i].mutex);
		if (!philos[i].last_meal.init)
			pthread_mutex_destroy(&philos[i].last_meal.mutex);
		if (!philos[i].meals_eaten.init)
			pthread_mutex_destroy(&philos[i].meals_eaten.mutex);
		i++;
	}
	if (!data->write.init)
		pthread_mutex_destroy(&data->write.mutex);
	if (!data->dead.init)
		pthread_mutex_destroy(&data->dead.mutex);
	if (!data->start.init)
		pthread_mutex_destroy(&data->start.mutex);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
		if (ft_mutex_init(&data->forks[i++]))
			return (1);
	data->write.value = 0;
	data->dead.value = 0;
	if (ft_mutex_init(&data->write))
		return (1);
	if (ft_mutex_init(&data->dead))
		return (1);
	if (ft_mutex_init(&data->start))
		return (1);
	return (0);
}
