/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:39:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 19:59:20 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "philo.h"

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

	if (parse_arguments(argc, argv, &data))
		return (1);
	if (init_philos_threads(&data))
		return (1);
	watcher(&data);
	join_philos_threads(&data);
	return (exit_succes(&data));
}
