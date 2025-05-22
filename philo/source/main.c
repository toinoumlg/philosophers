/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:39:04 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/22 18:51:38 by amalangu         ###   ########.fr       */
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

void	*philo_routine(void *philo_data)
{
	t_philo	*philo;
	int		alive;
	int		time_since_last_meal;

	alive = 1;
	time_since_last_meal = 0;
	philo = (t_philo *)philo_data;
	while (alive)
	{
	}
	return (NULL);
}

void	init_philos(t_philo *philo)
{
	int			i;
	pthread_t	threads[200];

	i = 0;
	while (i < philo->nbr_of_philo)
		pthread_create(&threads[i++], NULL, philo_routine, (void *)philo);
	i = 0;
	while (i < philo->nbr_of_philo)
		pthread_join(threads[i++], NULL);
}

int	main(int argc, char **argv)
{
	t_philo philo;
	parse_arguments(argc, argv, &philo);
	init_philos(&philo);
}