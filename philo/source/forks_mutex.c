/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:55:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 17:56:14 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "philo_struct.h"

void	destroy_mutex(pthread_mutex_t *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
		pthread_mutex_destroy(&forks[i++]);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(data->write, NULL);
}
