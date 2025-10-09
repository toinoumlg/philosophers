/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:56:51 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:51:30 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ft_time.h"
#include "mutex.h"
#include <unistd.h>

void	go_think(t_philo *philo)
{
	print_lock(philo, "is thinking");
}

int	mutex_value(t_mutex *mutex)
{
	int	value;

	pthread_mutex_lock(&mutex->mutex);
	value = mutex->value;
	pthread_mutex_unlock(&mutex->mutex);
	return (value);
}

void	go_eat(t_philo *philo)
{
	pick_up_forks(philo);
	set_value_last_meal(&philo->last_meal,
		get_time_since_start(philo->args->start));
	set_value_meal_eaten(&philo->meals_eaten);
	ft_usleep(philo->args->tt_eat * 1000, philo);
	release_forks(philo->fork_l, philo->fork_r);
}

void	go_sleep(t_philo *philo)
{
	if (!mutex_value(philo->dead))
	{
		print_lock(philo, "is sleeping");
		ft_usleep(philo->args->tt_sleep * 1000, philo);
	}
}

void	*philo_routine(void *add)
{
	t_philo	*philo;

	philo = (t_philo *)add;
	pthread_mutex_lock(&philo->start->mutex);
	pthread_mutex_unlock(&philo->start->mutex);
	if (mutex_value(philo->dead))
		return (NULL);
	set_value_last_meal(&philo->last_meal, 0);
	go_think(philo);
	while (!mutex_value(philo->dead))
	{
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}
