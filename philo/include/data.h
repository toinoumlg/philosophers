/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:49:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 17:02:59 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef data_H
# define data_H

# include <pthread.h>

typedef struct s_fork
{
	int				taken;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	int				is_eating;
	int				start;
	int				tt_sleep;
	int				tt_eat;
	int				last_meal;
	int				*dead_flag;
	int				*meal_flag;
	t_fork			*fork_l;
	t_fork			*fork_r;
	pthread_mutex_t	*write;
}					t_philo;

typedef struct s_data
{
	int				nbr_of_philo;
	int				meals_goal;
	int				dead_flag;
	int				meal_flag;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	t_fork			*forks;
	pthread_mutex_t	data_access;
	t_philo			*philos;
}					t_data;

#endif