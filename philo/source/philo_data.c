/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:56:45 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:21:09 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include "string.h"

int	new_philo(t_data *data, int i, int j, t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	philo->last_meal.init = 2;
	philo->meals_eaten.init = 2;
	philo->meals_eaten.value = 0;
	if (ft_lmutex_init(&philo->last_meal))
		return (1);
	if (ft_mutex_init(&philo->meals_eaten))
		return (1);
	philo->id = i + 1;
	philo->fork_l = &data->forks[i];
	philo->fork_r = &data->forks[j];
	philo->write = &data->write;
	philo->dead = &data->dead;
	philo->start = &data->start;
	philo->args = &data->args;
	return (0);
}

int	set_philos(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = 0;
	while (i < data->nbr_of_philo - 1)
	{
		if (new_philo(data, i, i + 1, &philos[i]))
			return (1);
		i++;
	}
	if (new_philo(data, i, 0, &philos[i]))
		return (1);
	return (0);
}
