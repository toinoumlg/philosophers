/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:37 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 20:14:06 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ft_time.h"
#include "mutex.h"
#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	print_lock(t_philo *philo, char *str)
{
	while (1)
	{
		if (mutex_value(philo->dead))
			return ;
		if (mutex_get(philo->write))
		{
			printf("%ld %d %s\n", get_time_since_start(philo->args->start),
				philo->id, str);
			set_value(philo->write, 0);
			break ;
		}
		else
			usleep(100);
	}
}
