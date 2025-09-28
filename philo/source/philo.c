/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:56:51 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 17:25:13 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "forks.h"
#include "print_lock.h"
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

void	go_think(t_philo *philo)
{
	print_think_lock(philo);
}

void	old_go_eat(t_philo *philo)
{
	pick_up_forks(philo);
	pthread_mutex_lock(philo->write);
	philo->is_eating = 1;
	pthread_mutex_unlock(philo->write);
	ft_usleep(philo->tt_eat * 1000);
	release_forks(philo->fork_l, philo->fork_r);
	pthread_mutex_lock(philo->write);
	philo->last_meal = get_time_since_start(philo->start);
	philo->is_eating = 0;
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->write);
}

int	is_taken(t_fork *fork)
{
	int	value;

	pthread_mutex_lock(&fork->mutex);
	value = fork->taken;
	pthread_mutex_unlock(&fork->mutex);
	return (value);
}

// taken[0] is fork_l and taken[1] fork_r
void	go_eat(t_philo *philo)
{
	while (1)
	{
		if (!is_taken(philo->fork_l) && !is_taken(philo->fork_r))
		{
			pick_up_forks(philo);
			philo->is_eating = 1;
			ft_usleep(philo->tt_eat * 1000);
			release_forks(philo->fork_l, philo->fork_r);
			philo->last_meal = get_time_since_start(philo->start);
			philo->is_eating = 0;
			return ;
		}
	}
}

void	go_sleep(t_philo *philo)
{
	print_sleep_lock(philo);
	ft_usleep(philo->tt_sleep * 1000);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;
	int		dead_flag;
	int		meal_flag;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(philo->write);
	philo->last_meal = philo->start;
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->write);
	while (1)
	{
		pthread_mutex_lock(philo->write);
		dead_flag = *philo->dead_flag;
		meal_flag = *philo->meal_flag;
		pthread_mutex_unlock(philo->write);
		if (dead_flag || meal_flag)
			break ;
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}
