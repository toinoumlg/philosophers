/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:23:54 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 00:32:27 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEX_H
# define MUTEX_H

# include "data.h"

void	pick_up_forks(t_philo *philo);
void	release_forks(t_mutex *fork1, t_mutex *fork2);

int		mutex_value(t_mutex *mutex);
void	set_value(t_mutex *mutex, int value);
void	set_value_last_meal(t_lmutex *mutex, long value);
void	set_value_meal_eaten(t_mutex *mutex);
int		mutex_get(t_mutex *fork);

void	print_lock(t_philo *philo, char *str);
void	init_mutex(t_data *data);
void	destroy_mutex(t_mutex *forks, int size);

#endif