/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:37 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/02 19:01:01 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include "philo.h"
#include "time.h"
#include <stdio.h>

int	get_print_mutex(t_philo *philo)
{
	while (is_taken(philo->write))
		if (is_taken(philo->end))
			return (0);
	set_value(philo->write, 1);
	return (1);
}

void	print_lock(t_philo *philo, char *str)
{
	int start = get_time_since_start(philo->args->start);

	if (get_print_mutex(philo))
	{
		printf("%d %d %s\n", start, philo->id, str);
		set_value(philo->write, 0);
	}
}