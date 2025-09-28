/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:15:23 by amalangu          #+#    #+#             */
/*   Updated: 2025/09/18 16:46:04 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	long	num;
	int		tmp;
	int		i;

	i = 0;
	num = 0;
	if (*str == '+')
		str++;
	while (is_digit(str[i]))
	{
		tmp = str[i++] - '0';
		num = num * 10 + tmp;
	}
	if (num > __INT_MAX__ || str[i])
		return (-1);
	return (num);
}
