/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:37 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 00:21:15 by amalangu         ###   ########.fr       */
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
	int start = get_time_since_start(philo->args->start);

	while (1)
	{
		if (mutex_value(philo->dead))
			return ;
		if (mutex_get(philo->write))
		{
			printf("%d %d %s\n", start, philo->id, str);
			break ;
		}
		else
			usleep(600);
	}
	set_value(philo->write, 0);
}