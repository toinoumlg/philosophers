/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:53:48 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 00:20:50 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_time.h"
#include "mutex.h"
#include <unistd.h>

void	release_forks(t_mutex *fork_l, t_mutex *fork_r)
{
	set_value(fork_l, 0);
	if (fork_l == fork_r)
		return ;
	set_value(fork_r, 0);
}

int	pick_up_fork(t_mutex *fork, t_philo *philo)
{
	while (1)
	{
		if (mutex_value(philo->dead))
			return (1);
		if (mutex_get(fork))
		{
			print_lock(philo, "has taken a fork");
			break ;
		}
		usleep(600);
	}
	return (0);
}

void	pick_up_forks(t_philo *philo)
{
	if (philo->fork_l == philo->fork_r)
	{
		pick_up_fork(philo->fork_l, philo);
		while (!mutex_value(philo->dead))
			usleep(600);
	}
	if (philo->id % 2 == 0)
	{
		if (pick_up_fork(philo->fork_l, philo) || pick_up_fork(philo->fork_r,
				philo))
			return ;
	}
	else
	{
		if (pick_up_fork(philo->fork_r, philo) || pick_up_fork(philo->fork_l,
				philo))
			return ;
	}
	print_lock(philo, "is eating");
}
