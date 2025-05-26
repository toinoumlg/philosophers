/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:56:51 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:24:50 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "forks.h"
#include "philo_struct.h"
#include "print_lock.h"
#include <unistd.h>

void	go_think(t_philo *philo)
{
	print_think_lock(philo);
}

void	go_eat(t_philo *philo)
{
	pick_up_forks(philo);
	pthread_mutex_lock(philo->write);
	philo->is_eating = 1;
	pthread_mutex_unlock(philo->write);
	usleep(philo->tt_eat * 1000);
	unlock_forks(philo->fork_l, philo->fork_r);
	pthread_mutex_lock(philo->write);
	philo->last_meal = get_time_since_start(philo->start);
	philo->is_eating = 0;
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->write);
}

void	go_sleep(t_philo *philo)
{
	print_sleep_lock(philo);
	usleep(philo->tt_sleep * 1000);
}

void	*start_philo_routine(void *philo_add)
{
	t_philo	*philo;
	int		dead_flag;
	int		meal_flag;

	philo = (t_philo *)philo_add;
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
