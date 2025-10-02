/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:07:57 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/02 19:03:04 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "atoi.h"
#include "data.h"
#include "mutex.h"
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	set_data(int argc, char **argv, t_data *data)
{
	data->nbr_of_philo = ft_atoi(argv[1]);
	if (argc == 6)
		data->args.meals_goal = ft_atoi(argv[5]);
	data->args.tt_die = ft_atoi(argv[2]);
	data->args.tt_eat = ft_atoi(argv[3]);
	data->args.tt_sleep = ft_atoi(argv[4]);
	if (data->nbr_of_philo < 0 || data->args.meals_goal < 0
		|| data->args.tt_die < 0 || data->args.tt_eat < 0
		|| data->args.tt_sleep < 0)
		exit_parsing("Wrong argument values");
}

void	alloc_data(t_data *data)
{
	data->forks = malloc(sizeof(t_mutex) * data->nbr_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!data->forks || !data->philos)
		return (exit_alloc(data));
	memset(data->philos, 0, sizeof(t_philo) * data->nbr_of_philo);
	memset(data->forks, 0, sizeof(t_mutex) * data->nbr_of_philo);
}

void	parse_arguments(int argc, char **argv, t_data *data)
{
	memset(data, 0, sizeof(t_data));
	if (argc < 5 || argc > 6)
		return (exit_parsing("Wrong argument count"));
	set_data(argc, argv, data);
	alloc_data(data);
	init_mutex(data);
	set_philos(data);
}
