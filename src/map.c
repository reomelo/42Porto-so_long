/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <riolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:10:12 by riolivei          #+#    #+#             */
/*   Updated: 2023/11/02 16:25:27 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(const char *argv, t_props *props)
{
	int		count;
	int		fd;

	props->map.buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!props->map.buff)
		return (0);
	fd = open(argv, O_RDONLY);
	count = read(fd, props->map.buff, BUFFER_SIZE);
	if (count == -1)
	{
		free(props->map.buff);
		return (-1);
	}
	props->map.buff[count] = '\0';
	props->map.map = ft_split(props, '\n');
	if (!lines_len(props) || !val_chars(props) || !chars_count(props)
		|| !map_struct(props) || !path(props))
	{
		free(props->map.buff);
		return (0);
	}
	return (1);
}

int	val_chars(t_props *props)
{
	int	i;

	i = -1;
	while (props->map.buff[++i])
	{
		if (props->map.buff[i] != '0' && props->map.buff[i] != '1'
			&& props->map.buff[i] != 'C' && props->map.buff[i] != 'E'
			&& props->map.buff[i] != 'P' && props->map.buff[i] != '\n')
			return (0);
	}
	return (1);
}

int	chars_count(t_props *props)
{
	int		i;
	int		flags[3];

	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	i = -1;
	while (props->map.buff[++i])
	{
		if (props->map.buff[i] == 'C')
			flags[0]++;
		else if (props->map.buff[i] == 'E')
			flags[1]++;
		else if (props->map.buff[i] == 'P')
			flags[2]++;
	}
	if (flags[0] < 1 || flags[1] != 1 || flags[2] != 1)
		return (0);
	return (1);
}

int	map_struct(t_props *props)
{
	int	i;
	int	flag;

	i = -1;
	while (props->map.buff[++i] != '\n')
	{
		if (props->map.buff[i] != '1')
			return (0);
	}
	flag = map_walls(props, props->map.lines);
	if ((props->map.cols >= 5 && props->map.lines >= 3)
		&& (props->map.cols != props->map.lines) && flag)
		return (1);
	return (0);
}

int	map_walls(t_props *props, int lines)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (props->map.buff[++i])
	{
		if (counter == lines - 1 && props->map.buff[i] != '1')
			return (0);
		else if (props->map.buff[i] == '\n')
		{
			if (props->map.buff[i + 1] != '1' || props->map.buff[i - 1] != '1')
				return (0);
			counter++;
		}
	}
	return (1);
}
