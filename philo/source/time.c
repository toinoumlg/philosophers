/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:06:43 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 17:11:51 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <sys/time.h>

int	get_time_since_start(__ssize_t start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((int)(((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - start));
}
