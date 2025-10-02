/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:56:51 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/02 19:41:31 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
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

void	go_think(t_philo *philo)
{
	print_lock(philo, "is thinking");
}

int	is_taken(t_mutex *mutex)
{
	int	value;

	pthread_mutex_lock(&mutex->mutex);
	value = mutex->taken;
	pthread_mutex_unlock(&mutex->mutex);
	return (value);
}

void	lock_data_access(t_philo *philo)
{
	while (is_taken(&philo->data_access))
		usleep(100);
	set_value(&philo->data_access, 1);
}

void	go_eat(t_philo *philo)
{
	while (!is_taken(philo->end))
	{
		if (!is_taken(philo->fork_l) && !is_taken(philo->fork_r))
		{
			pick_up_forks(philo);
			lock_data_access(philo);
			philo->last_meal = get_time_since_start(philo->args->start);
			philo->is_eating = 1;
			set_value(&philo->data_access, 0);
			ft_usleep(philo->args->tt_eat * 1000);
			lock_data_access(philo);
			philo->meals_eaten++;
			philo->is_eating = 0;
			set_value(&philo->data_access, 0);
			release_forks(philo->fork_l, philo->fork_r);
			return ;
		}
	}
}

void	go_sleep(t_philo *philo)
{
	if (!is_taken(philo->end))
	{
		print_lock(philo, "is sleeping");
		ft_usleep(philo->args->tt_sleep * 1000);
	}
}

void	*philo_routine(void *add)
{
	t_philo	*philo;

	philo = (t_philo *)add;
	philo->last_meal = 0;
	while (!is_taken(philo->end))
	{
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}
