/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:06:43 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/08 23:43:45 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

void	ft_usleep(int ms)
{
	int	time_sleeped;

	time_sleeped = ms / 10;
	while (ms)
	{
		usleep(time_sleeped);
		ms = ms - time_sleeped;
	}
}

long	get_time_since_start(long start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}
