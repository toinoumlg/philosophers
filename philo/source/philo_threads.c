/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:03:06 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 17:58:29 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "philo_struct.h"
#include "philo_threads.h"
#include "philo.h"

#include <sys/time.h>

void	init_philos_threads(t_data *data)
{
	int				i;
	struct timeval	tv;
	size_t			start;

	i = 0;
	gettimeofday(&tv, NULL);
	start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	while (i < data->nbr_of_philo)
	{
		data->philos[i].start = start;
		pthread_create(&data->philos[i].thread, NULL, start_philo_routine,
			(void *)&data->philos[i]);
		i++;
	}
}

void	join_philos_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
		pthread_join(data->philos[i++].thread, NULL);
}
