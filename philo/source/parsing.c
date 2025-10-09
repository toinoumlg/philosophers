/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:07:57 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 20:33:24 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"
#include "data.h"
#include "mutex.h"
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	set_data(int argc, char **argv, t_data *data)
{
	data->nbr_of_philo = ft_atoi(argv[1]);
	if (argc == 6)
		data->args.meals_goal = ft_atoi(argv[5]);
	else
		data->args.meals_goal = -2;
	data->args.tt_die = ft_atoi(argv[2]);
	data->args.tt_eat = ft_atoi(argv[3]);
	data->args.tt_sleep = ft_atoi(argv[4]);
	if (data->nbr_of_philo <= 0 || (data->args.meals_goal == -1
			|| !data->args.meals_goal) || data->args.tt_die < 0
		|| data->args.tt_eat < 0 || data->args.tt_sleep < 0)
		return (exit_parsing("Wrong argument values"));
	return (0);
}

void	set_init_forks(t_mutex *mutex, int nbr_of_philo)
{
	int	i;

	i = 0;
	while (i < nbr_of_philo)
	{
		mutex->init = 2;
		mutex->value = 0;
		i++;
	}
}

int	alloc_data(t_data *data)
{
	data->forks = malloc(sizeof(t_mutex) * data->nbr_of_philo);
	if (!data->forks)
		return (exit_alloc(data));
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!data->philos)
	{
		free(data->forks);
		return (exit_alloc(data));
	}
	memset(data->philos, 0, sizeof(t_philo) * data->nbr_of_philo);
	memset(data->forks, 0, sizeof(t_mutex) * data->nbr_of_philo);
	set_init_forks(data->forks, data->nbr_of_philo);
	data->start.init = 2;
	data->dead.init = 2;
	data->write.init = 2;
	return (0);
}

int	free_parsing(t_data *data)
{
	ft_mutex_destroy(data);
	free(data->forks);
	free(data->philos);
	return (1);
}

int	parse_arguments(int argc, char **argv, t_data *data)
{
	memset(data, 0, sizeof(t_data));
	if (argc < 5 || argc > 6)
		return (exit_parsing("Wrong argument count"));
	if (set_data(argc, argv, data))
		return (1);
	if (alloc_data(data))
		return (1);
	if (init_mutex(data))
		return (free_parsing(data));
	if (set_philos(data))
		return (free_parsing(data));
	return (0);
}
