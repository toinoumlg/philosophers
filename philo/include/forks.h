/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:23:54 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:31:37 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H

# include "philo_struct.h"

void	pick_up_forks(t_philo *philo);
void	unlock_forks(pthread_mutex_t *fork1, pthread_mutex_t *fork2);

#endif