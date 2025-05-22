/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:39:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/22 17:13:14 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	parse_arguments(int argc, char **argv, t_philo *philo)
{
	if (argc < 5 || argc > 7)
		exit(1);
	philo->nbr_of_philo = atoi(argv[1]);
	philo->t_to_die = atoi(argv[2]);
	philo->t_to_eat = atoi(argv[3]);
	philo->t_to_sleep = atoi(argv[4]);
	return ;
}

int	main(int argc, char **argv)
{
	t_philo philo;
	parse_arguments(argc, argv, &philo);
	(void)argc;
	(void)argv;
	(void)philo;
}