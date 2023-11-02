/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:58:07 by riolivei          #+#    #+#             */
/*   Updated: 2022/12/04 16:46:43 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_path(char **sol, t_props *props, int l, int c)
{
	int	count;

	count = 0;
	if (props->map.map[l][c] == 'E')
		props->map.exit_ok = true;
	if (props->map.map[l][c] == 'C' && sol[l][c] != 1)
		count++;
	if (sol[l][c] == 1)
		return (count);
	if (is_valid(props, l, c) == false)
		return (count);
	sol[l][c] = 1;
	count += find_path(sol, props, l + 1, c);
	count += find_path(sol, props, l, c + 1);
	count += find_path(sol, props, l - 1, c);
	count += find_path(sol, props, l, c - 1);
	return (count);
}

bool	is_valid(t_props *props, int l, int c)
{
	if (l >= 0 && l < props->map.lines && c >= 0 && c < props->map.cols
		&& props->map.map[l][c] != '1')
		return (true);
	return (false);
}

char	**solution(int lines, int cols)
{
	char	**sol;
	int		l;

	sol = (char **)malloc((lines + 1) * sizeof(char *));
	if (!sol)
		return (NULL);
	sol[lines] = 0;
	l = -1;
	while (++l < lines)
	{
		sol[l] = new_line(cols);
		if (!sol[l])
			return (NULL);
	}
	return (sol);
}
