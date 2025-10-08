/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:49:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 00:02:13 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef data_H
# define data_H

# include <pthread.h>

typedef struct s_mutex
{
	int				value;
	pthread_mutex_t	mutex;
}					t_mutex;

typedef struct s_lmutex
{
	long			value;
	pthread_mutex_t	mutex;
}					t_lmutex;

typedef struct s_args
{
	int				tt_eat;
	int				tt_sleep;
	int				tt_die;
	int				meals_goal;
	long			start;
}					t_args;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_args			*args;
	t_lmutex		last_meal;
	t_mutex			meals_eaten;
	t_mutex			*write;
	t_mutex			*dead;
	t_mutex			*fork_l;
	t_mutex			*fork_r;
}					t_philo;

typedef struct s_data
{
	int				nbr_of_philo;
	t_args			args;
	t_mutex			*forks;
	t_mutex			write;
	t_mutex			dead;
	t_philo			*philos;
}					t_data;

int					exit_succes(t_data *data);
void				exit_parsing(char *str);
void				exit_alloc(t_data *data);

#endif