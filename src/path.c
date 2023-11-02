/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <riolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:55:54 by riolivei          #+#    #+#             */
/*   Updated: 2023/11/02 16:25:15 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*new_line(int cols)
{
	char	*str;
	int		i;

	str = (char *)malloc((cols) * sizeof(char));
	if (!str)
		return (NULL);
	str[cols] = '\0';
	i = -1;
	while (++i < cols)
		str[i] = '0';
	return (str);
}

void	positions(t_props *props)
{
	int	l;
	int	c;

	l = -1;
	while (props->map.map[++l])
	{
		c = -1;
		while (props->map.map[l][++c])
		{
			if (props->map.map[l][c] == 'P')
			{
				props->player_x = l;
				props->player_y = c;
			}

			if (props->map.map[l][c] == 'E')
			{
				props->exit_x = l;
				props->exit_y = c;
			}
		}
	}
}

int	path(t_props *props)
{
	char	**sol;

	positions(props);
	props->map.count = colect(props);
	sol = solution(props->map.lines, props->map.cols);
	if (!sol)
		return (0);
	if (find_path(sol, props, props->player_x, props->player_y)
		== props->map.count)
	{
		if (props->map.exit_ok == false)
			return (0);
		return (1);
	}
	return (0);
}

int	validate_extension(const char *argv)
{
	int		len;
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	len = ft_strlen((char *)argv) - 1;
	s1 = ".ber";
	s2 = (char *)malloc(5 * sizeof(char));
	if (!s2)
		return (0);
	s2[4] = '\0';
	i = -1;
	j = 4;
	while (++i < 4)
		s2[i] = argv[len - (--j)];
	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
