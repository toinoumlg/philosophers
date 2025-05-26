/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:54:25 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:23:58 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREADS_H
# define PHILO_THREADS_H

# include "data_struct.h"

void	init_philos_threads(t_data *data);
void	join_philos_threads(t_data *data);

#endif