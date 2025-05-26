/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalangu <amalangu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:52:51 by amalangu          #+#    #+#             */
/*   Updated: 2025/05/26 18:06:59 by amalangu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "data_struct.h"

int		exit_succes(t_data *data);
void	exit_parsing(char *str);
void	exit_alloc(t_data *data);

#endif