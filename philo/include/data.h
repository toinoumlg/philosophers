/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:49:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:49:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <pthread.h>

typedef struct s_mutex
{
	int				value;
	int				init;
	pthread_mutex_t	mutex;
}					t_mutex;

typedef struct s_lmutex
{
	long			value;
	int				init;
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
	t_mutex			*start;
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
	t_mutex			start;
	t_philo			*philos;
}					t_data;

int					parse_arguments(int argc, char **argv, t_data *data);

void				watcher(t_data *data);

int					exit_succes(t_data *data);
int					exit_parsing(char *str);
int					exit_alloc(t_data *data);

#endif