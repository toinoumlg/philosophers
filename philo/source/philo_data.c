/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:56:45 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/02 19:06:19 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "string.h"

t_philo	new_philo(t_data *data, int i, int j)
{
	t_philo	new;

	memset(&new, 0, sizeof(t_philo));
	pthread_mutex_init(&new.data_access.mutex, NULL);
	new.id = i + 1;
	new.fork_l = &data->forks[i];
	new.fork_r = &data->forks[j];
	new.write = &data->write;
	new.end = &data->end;
	new.args = &data->args;
	return (new);
}

void	set_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = 0;
	while (i < data->nbr_of_philo - 1)
	{
		philos[i] = new_philo(data, i, i + 1);
		i++;
	}
	philos[i] = new_philo(data, i, 0);
}
