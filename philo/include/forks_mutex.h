/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_mutex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:14:08 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 15:54:10 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_MUTEX_H
# define FORKS_MUTEX_H

# include "data.h"

void	destroy_mutex(t_fork *forks, int size);
void	init_mutex(t_data *data);

#endif