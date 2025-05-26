/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:56:45 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:21:37 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"

void	set_philos_data(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		philos[i].dead_flag = &data->dead_flag;
		philos[i].meal_flag = &data->meal_flag;
		philos[i].tt_eat = data->tt_eat;
		philos[i++].tt_sleep = data->tt_sleep;
	}
}

void	set_philos_mutex(t_philo *philos, pthread_mutex_t *forks, int size,
		pthread_mutex_t *write)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		philos[i].id = i + 1;
		philos[i].fork_l = &forks[i];
		philos[i].fork_r = &forks[i + 1];
		philos[i].write = write;
	}
	philos[i].id = i + 1;
	philos[i].write = write;
	philos[i].fork_l = &forks[i];
	philos[i].fork_r = &forks[0];
}
