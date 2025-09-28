/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:20:18 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 16:41:38 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include "data.h"

void	set_philos_mutex(t_philo *philos, t_fork *forks, int size,
			pthread_mutex_t *write);
void	set_philos_data(t_philo *philos, t_data *data);

#endif