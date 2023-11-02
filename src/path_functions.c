/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:15:35 by riolivei          #+#    #+#             */
/*   Updated: 2022/12/04 15:28:06 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	colect(t_props *props)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (props->map.buff[++i])
	{
		if (props->map.buff[i] == 'C')
			count++;
	}
	return (count);
}

int	line_counter(t_props *props)
{
	int	lines;
	int	i;

	i = -1;
	lines = 0;
	while (props->map.buff[++i])
	{
		if (props->map.buff[i] == '\n')
			lines++;
	}
	return (lines + 1);
}
