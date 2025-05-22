/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:37:20 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/22 17:09:04 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
	int	nbr_of_philo;
	int	t_to_die;
	int	t_to_eat;
	int	t_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}		t_philo;
