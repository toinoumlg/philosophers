/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:37:20 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/25 19:21:19 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	size_t			start;
	size_t			tt_sleep;
	size_t			tt_eat;
	size_t			last_meal;
	int				nbr_of_t_each_philo_eat;
	int				*dead_flag;
	int				*meal_flag;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*write;
}					t_philo;

typedef struct s_data
{
	int				nbr_of_philo;
	int				meals_goal;
	int				dead_flag;
	int				meal_flag;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*write;
	t_philo			*philos;
}					t_data;
