/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:55:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 17:13:38 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>

void	destroy_mutex(t_fork *forks, int size)
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
	pthread_mutex_init(&data->data_access, NULL);
}
