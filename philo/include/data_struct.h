/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:49:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:07:19 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# include "philo_struct.h"
# include <pthread.h>

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

#endif