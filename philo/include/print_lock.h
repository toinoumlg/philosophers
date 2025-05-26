/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:17:01 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:18:35 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_LOCK_H
# define PRINT_LOCK_H

# include "philo_threads.h"

void	print_think_lock(t_philo *philo);
void	print_sleep_lock(t_philo *philo);
void	print_fork_lock(t_philo *philo);
void	print_eat_lock(t_philo *philo);
void	print_dead_lock(t_philo *philo);

#endif