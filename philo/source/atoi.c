/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:15:23 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:10:29 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

int	my_atoi(char *str)
{
	int	num;
	int	tmp;
	int	i;

	i = -1;
	num = 0;
	if (*str == '+')
		str++;
	while (str[++i])
	{
		tmp = str[i] - 48;
		num = num * 10 + tmp;
	}
	return (num);
}

size_t	atosize_t(char *str)
{
	size_t	num;
	int		tmp;
	int		i;

	i = -1;
	num = 0;
	if (*str == '+')
		str++;
	while (str[++i])
	{
		tmp = str[i] - 48;
		num = num * 10 + tmp;
	}
	return (num);
}
