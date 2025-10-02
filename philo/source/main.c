/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:39:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/02 14:16:10 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "parse.h"
#include "philo.h"
#include "watcher.h"

/*
	number_of_philosophers
	time_to_die
	time_to_eat
	time_to_sleep
	[number_of_times_each_philosopher_must_eat]
*/
int	main(int argc, char **argv)
{
	t_data	data;

	parse_arguments(argc, argv, &data);
	init_philos_threads(&data);
	set_watcher(&data);
	join_philos_threads(&data);
	return (exit_succes(&data));
}
