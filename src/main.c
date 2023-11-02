/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <riolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:50:02 by riolivei          #+#    #+#             */
/*   Updated: 2023/11/02 16:42:04 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initiate(t_props *props)
{
	props->map.lines = 0;
	props->map.cols = 0;
	props->map.count = 0;
	props->map.exit_ok = false;
	props->steps = 0;
	props->player_x = 0;
	props->player_y = 0;
	props->exit_x = 0;
	props->exit_y = 0;
	props->mlx.mlx_ptr = NULL;
	props->mlx.win_ptr = NULL;
	props->tilemap = NULL;
	props->images.is_left = false;
	props->images.current_player_idle = 0;
	props->images.floor = NULL;
	props->images.player = NULL;
	props->images.player_left = NULL;
	props->images.player_right = NULL;
	props->images.wall = NULL;
	props->images.colectible = NULL;
	props->images.exit = NULL;
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub_str;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub_str = malloc(1 * sizeof(char));
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	sub_str = malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	i = 0;
	while (i < len)
		sub_str[i++] = s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	lines_len(t_props *props)
{
	int	*lens;
	int	i;

	if (!props->map.map)
		return (0);
	i = -1;
	lens = (int *)malloc((props->map.lines + 1) * sizeof(int));
	if (!lens)
		return (0);
	lens[props->map.lines] = '\0';
	while (++i < props->map.lines)
		lens[i] = ft_strlen(props->map.map[i]);
	i = -1;
	while (lens[++i])
	{
		if (lens[i] != props->map.cols)
		{
			free(lens);
			return (0);
		}
	}
	free(lens);
	return (1);
}

int	main(int argc, const char *argv[])
{
	int		res;
	t_props	props;

	if (argc != 2)
		return (0);
	if (!validate_extension(argv[1]))
		handle_errors("Error\nInvalid type of the file!\n");
	initiate(&props);
	res = validate_map(argv[1], &props);
	if (res == -1)
		handle_errors("Error\nInvalid read of the file!\n");
	else if (res == 0)
		handle_errors("Error\nInvalid map!\n");
	else
	{
		props.mlx.mlx_ptr = mlx_init();
		props.mlx.win_ptr = mlx_new_window(props.mlx.mlx_ptr,
				TILES_SIZE * props.map.cols,
				TILES_SIZE * props.map.lines, "Magic Wizard");
		ready_map(&props);
		hooks(&props);
	}
	return (0);
}
