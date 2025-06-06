/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:39:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:13:43 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_threads.h"
#include "data_struct.h"
#include "parse.h"
#include "exit.h"
#include "watcher.h"

int	main(int argc, char **argv)
{
	t_data	data;

	parse_arguments(argc, argv, &data);
	init_philos_threads(&data);
	set_watcher(&data);
	join_philos_threads(&data);
	return (exit_succes(&data));
}
