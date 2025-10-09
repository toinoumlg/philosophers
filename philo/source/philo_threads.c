/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:03:06 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:49:15 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include "philo.h"
#include <stdlib.h>
#include <sys/time.h>

int	init_philos_threads(t_data *data)
{
	int				i;
	struct timeval	tv;

	i = 0;
	pthread_mutex_lock(&data->start.mutex);
	while (i < data->nbr_of_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				(void *)&data->philos[i]))
		{
			data->nbr_of_philo = i - 1;
			set_value(&data->dead, 1);
			pthread_mutex_unlock(&data->start.mutex);
			join_philos_threads(data);
			free(data->forks);
			free(data->philos);
			return (1);
		}
		i++;
	}
	gettimeofday(&tv, NULL);
	data->args.start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	pthread_mutex_unlock(&data->start.mutex);
	return (0);
}

void	join_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
		pthread_join(data->philos[i++].thread, NULL);
}
