/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:37:20 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:14:15 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

void	*philo_routine(void *philo_ptr);

int		set_philos(t_data *data);

int		init_philos_threads(t_data *data);
void	join_philos_threads(t_data *data);

#endif
