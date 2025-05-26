/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:37:20 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:08:16 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	int				is_eating;
	size_t			start;
	size_t			tt_sleep;
	size_t			tt_eat;
	size_t			last_meal;
	int				*dead_flag;
	int				*meal_flag;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*write;
}					t_philo;

#endif