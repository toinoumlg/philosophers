/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:37 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:16:38 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include <stdio.h>

void	print_think_lock(t_philo *philo)
{
	size_t	start;
	int		id;
	int		dead_flag;

	pthread_mutex_lock(philo->write);
	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	pthread_mutex_unlock(philo->write);
	if (dead_flag)
		return ;
	printf("%ld %d is thinking\n", start, id);
}

void	print_sleep_lock(t_philo *philo)
{
	size_t	start;
	int		id;
	int		dead_flag;

	pthread_mutex_lock(philo->write);
	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	pthread_mutex_unlock(philo->write);
	if (dead_flag)
		return ;
	printf("%ld %d is sleeping\n", start, id);
}

void	print_fork_lock(t_philo *philo)
{
	size_t	start;
	int		id;
	int		dead_flag;

	pthread_mutex_lock(philo->write);
	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	pthread_mutex_unlock(philo->write);
	if (dead_flag)
		return ;
	printf("%ld %d has taken a fork\n", start, id);
}

void	print_eat_lock(t_philo *philo)
{
	size_t	start;
	int		id;
	int		dead_flag;

	pthread_mutex_lock(philo->write);
	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	pthread_mutex_unlock(philo->write);
	if (dead_flag)
		return ;
	printf("%ld %d is eating\n", start, id);
}

void	print_dead_lock(t_philo *philo)
{
	size_t	start;
	int		id;

	pthread_mutex_lock(philo->write);
	start = get_time_since_start(philo->start);
	id = philo->id;
	pthread_mutex_unlock(philo->write);
	printf("%ld %d died\n", start, id);
}
