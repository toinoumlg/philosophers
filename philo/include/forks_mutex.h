/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_mutex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:14:08 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:15:33 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_MUTEX_H
# define FORKS_MUTEX_H

# include "data_struct.h"

void	destroy_mutex(pthread_mutex_t *forks, int size);
void	init_mutex(t_data *data);

#endif