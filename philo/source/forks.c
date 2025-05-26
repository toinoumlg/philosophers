/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:53:48 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:18:45 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_struct.h"
#include "print_lock.h"
#include <unistd.h>

void	unlock_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2)
{
	if (fork1 == fork2)
	{
		pthread_mutex_unlock(fork1);
		return ;
	}
	pthread_mutex_unlock(fork1);
	pthread_mutex_unlock(fork2);
}

void	pick_up_fork(pthread_mutex_t *fork, t_philo *philo)
{
	pthread_mutex_lock(fork);
	print_fork_lock(philo);
}

void	wait_for_death(t_philo *philo)
{
	int	dead_flag;

	while (1)
	{
		pthread_mutex_lock(philo->write);
		dead_flag = *philo->dead_flag;
		pthread_mutex_unlock(philo->write);
		if (dead_flag)
			return ;
		usleep(1000);
	}
}

void	pick_up_forks(t_philo *philo)
{
	if (philo->fork_l == philo->fork_r)
	{
		pick_up_fork(philo->fork_l, philo);
		return (wait_for_death(philo));
	}
	if (philo->id % 2 == 0)
	{
		pick_up_fork(philo->fork_l, philo);
		pick_up_fork(philo->fork_r, philo);
	}
	else
	{
		pick_up_fork(philo->fork_r, philo);
		pick_up_fork(philo->fork_l, philo);
	}
	print_eat_lock(philo);
}
