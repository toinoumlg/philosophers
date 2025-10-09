/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:08:59 by amalangu          #+#    #+#             */
/*   Updated: 2025/10/09 18:02:00 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "mutex.h"
#include <stdio.h>
#include <stdlib.h>

int	exit_parsing(char *str)
{
	printf("Error\n%s\n", str);
	return (1);
}

int	exit_alloc(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	printf("Error\nFailed malloc\n");
	return (1);
}

int	exit_succes(t_data *data)
{
	ft_mutex_destroy(data);
	free(data->forks);
	free(data->philos);
	return (EXIT_SUCCESS);
}
