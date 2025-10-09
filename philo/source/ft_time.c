/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:06:43 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 20:14:01 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include <sys/time.h>
#include <unistd.h>

void	ft_usleep(int ms, t_philo *philo)
{
	struct timeval	tv;
	long			start;

	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (1)
	{
		gettimeofday(&tv, NULL);
		if (mutex_value(philo->dead))
			return ;
		if (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start > ms / 1000)
			return ;
		usleep(100);
	}
}

long	get_time_since_start(long start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}
