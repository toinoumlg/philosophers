/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:53:48 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/02 18:47:18 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutex.h"
#include <unistd.h>

static void	ft_usleep(int ms)
{
	int	time_sleeped;

	time_sleeped = ms / 10;
	while (ms)
	{
		usleep(time_sleeped);
		ms = ms - time_sleeped;
	}
}

void	set_value(t_mutex *mutex, int value)
{
	pthread_mutex_lock(&mutex->mutex);
	mutex->taken = value;
	pthread_mutex_unlock(&mutex->mutex);
}

void	release_forks(t_mutex *fork_l, t_mutex *fork_r)
{
	set_value(fork_l, 0);
	if (fork_l == fork_r)
		return ;
	set_value(fork_r, 0);
}

void	pick_up_fork(t_mutex *fork, t_philo *philo)
{
	set_value(fork, 1);
	print_lock(philo, "has taken a fork");
}

void	wait_for_death(t_philo *philo)
{
	while (!is_taken(philo->end))
		ft_usleep(500);
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
	print_lock(philo, "is eating");
}
