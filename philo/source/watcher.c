/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:14 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 20:32:58 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ft_time.h"
#include "mutex.h"
#include "watcher.h"
#include <unistd.h>

int	check_for_death(t_data *data)
{
	int		i;
	long	start;

	i = 0;
	start = get_time_since_start(data->args.start);
	while (i < data->nbr_of_philo)
	{
		if (start - get_last_meal_value(&data->philos[i].last_meal)
			> data->args.tt_die)
			return (print_dead_lock(&data->philos[i], data));
		i++;
	}
	return (0);
}

int	check_for_meals_goal(t_data *data)
{
	int	i;

	i = 0;
	if (data->args.meals_goal == -2)
		return (0);
	while (i < data->nbr_of_philo)
	{
		if (get_meals_eaten(&data->philos[i]) > data->args.meals_goal)
			i++;
		else
			return (0);
	}
	set_value(&data->write, 1);
	set_value(&data->dead, 1);
	return (1);
}

void	watcher(t_data *data)
{
	if (mutex_value(&data->dead))
		return ;
	while (1)
	{
		if (check_for_death(data))
			break ;
		if (check_for_meals_goal(data))
			break ;
		usleep(100);
	}
}
