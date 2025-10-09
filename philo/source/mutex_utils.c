/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:49:22 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:28:09 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	mutex_get(t_mutex *mutex)
{
	if (!mutex)
		return (0);
	pthread_mutex_lock(&mutex->mutex);
	if (!mutex->value)
	{
		mutex->value = 1;
		pthread_mutex_unlock(&mutex->mutex);
		return (1);
	}
	pthread_mutex_unlock(&mutex->mutex);
	return (0);
}

void	set_value(t_mutex *mutex, int value)
{
	if (!mutex)
		return ;
	pthread_mutex_lock(&mutex->mutex);
	mutex->value = value;
	pthread_mutex_unlock(&mutex->mutex);
}

int	ft_mutex_init(t_mutex *mutex)
{
	if (pthread_mutex_init(&mutex->mutex, NULL))
	{
		mutex->init = 1;
		return (1);
	}
	mutex->init = 0;
	return (0);
}

int	ft_lmutex_init(t_lmutex *mutex)
{
	if (pthread_mutex_init(&mutex->mutex, NULL))
	{
		mutex->init = 1;
		return (1);
	}
	mutex->init = 0;
	return (0);
}
