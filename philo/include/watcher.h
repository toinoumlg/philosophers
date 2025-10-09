/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:12:33 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 20:00:11 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATCHER_H
# define WATCHER_H

# include "data.h"

int		get_meals_eaten(t_philo *philo);
long	get_last_meal_value(t_lmutex *last_meal);
int		print_dead_lock(t_philo *philo, t_data *data);

#endif
