/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:08:59 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:59:55 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_struct.h"
#include "forks_mutex.h"
#include <stdio.h>
#include <stdlib.h>

void	exit_parsing(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	exit_alloc(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data->data_access)
		free(data->data_access);
	printf("Error\nFailed malloc\n");
	exit(EXIT_FAILURE);
}

int	exit_succes(t_data *data)
{
	destroy_mutex(data->forks, data->nbr_of_philo);
	pthread_mutex_destroy(data->data_access);
	free(data->forks);
	free(data->philos);
	free(data->data_access);
	return (EXIT_SUCCESS);
}
