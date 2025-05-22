/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:37:20 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/22 17:59:59 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo
{
	int	nbr_of_philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}		t_philo;
