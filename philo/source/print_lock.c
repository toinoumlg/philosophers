/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:37 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 17:12:45 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>

void	print_think_lock(t_philo *philo)
{
	int	start;
	int	id;
	int	dead_flag;

	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	if (dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%d %d is thinking\n", start, id);
	pthread_mutex_unlock(philo->write);
}

void	print_sleep_lock(t_philo *philo)
{
	int	start;
	int	id;
	int	dead_flag;

	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	if (dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%d %d is sleeping\n", start, id);
	pthread_mutex_unlock(philo->write);
}

void	print_fork_lock(t_philo *philo)
{
	int	start;
	int	id;
	int	dead_flag;

	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	if (dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%d %d has taken a fork\n", start, id);
	pthread_mutex_unlock(philo->write);
}

void	print_eat_lock(t_philo *philo)
{
	int	start;
	int	id;
	int	dead_flag;

	start = get_time_since_start(philo->start);
	id = philo->id;
	dead_flag = *philo->dead_flag;
	if (dead_flag)
		return ;
	pthread_mutex_lock(philo->write);
	printf("%d %d is eating\n", start, id);
	pthread_mutex_unlock(philo->write);
}

void	print_dead_lock(t_philo *philo)
{
	int	start;
	int	id;

	start = get_time_since_start(philo->start);
	id = philo->id;
	pthread_mutex_lock(philo->write);
	printf("%d %d died\n", start, id);
	pthread_mutex_unlock(philo->write);
}
