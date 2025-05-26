/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:07:57 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:23:19 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "forks_mutex.h"
#include "philo_data.h"
#include "atoi.h"
#include "exit.h"
#include <stdlib.h>
#include <string.h>

void	check_argc(int argc)
{
	if (argc < 5 || argc > 6)
		return (exit_parsing("Wrong argument size"));
}

void	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+')
				(argv[i])++;
			while (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			if (j == 0 || argv[i][j] > 0)
				return (exit_parsing("Wrong charater(s) in arg(s)"));
		}
	}
	return ;
}

void	set_data(int argc, char **argv, t_data *data)
{
	data->dead_flag = 0;
	data->meal_flag = 0;
	data->nbr_of_philo = my_atoi(argv[1]);
	if (argc == 6)
		data->meals_goal = my_atoi(argv[5]);
	else
		data->meals_goal = -1;
	data->tt_die = atosize_t(argv[2]);
	data->tt_eat = atosize_t(argv[3]);
	data->tt_sleep = atosize_t(argv[4]);
}

void	alloc_data(t_data *data)
{
	data->write = malloc(sizeof(pthread_mutex_t));
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!data->write || !data->forks || !data->philos)
		return (exit_alloc(data));
	memset(data->philos, 0, sizeof(t_philo) * data->nbr_of_philo);
}

void	parse_arguments(int argc, char **argv, t_data *data)
{
	check_argc(argc);
	check_argv(argv);
	set_data(argc, argv, data);
	alloc_data(data);
	init_mutex(data);
	set_philos_mutex(data->philos, data->forks, data->nbr_of_philo,
		data->write);
	set_philos_data(data->philos, data);
	return ;
}
