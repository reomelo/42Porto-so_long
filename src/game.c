/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <riolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:55:46 by riolivei          #+#    #+#             */
/*   Updated: 2023/11/02 16:46:19 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_image(t_props *props)
{
	int	img_size;

	img_size = 64;
	props->images.floor = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, FLOOR_TILE, &img_size, &img_size);
	props->images.wall = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, WALL_TILE, &img_size, &img_size);
	props->images.player = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, PLAYER_TILE, &img_size, &img_size);
	props->images.player_left = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, PLAYER_LEFT_TILE, &img_size, &img_size);
	props->images.player_right = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, PLAYER_RIGHT_TILE, &img_size, &img_size);
	props->images.colectible = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, COLECTIBLE_TILE, &img_size, &img_size);
	props->images.exit = mlx_xpm_file_to_image(
			props->mlx.mlx_ptr, EXIT_TILE, &img_size, &img_size);
}

void	props_map(t_props *props)
{
	int	l;
	int	c;

	props->tilemap = malloc((props->map.lines + 1) * sizeof(t_tilemap *));
	if (!props->tilemap)
		handle_errors("Falha no tilemap");
	l = -1;
	while (++l < props->map.lines)
	{
		props->tilemap[l] = malloc((props->map.cols + 1) * sizeof(t_tilemap));
		if (!props->tilemap[l])
			handle_errors("Falha no tilemap");
		c = -1;
		while (++c < props->map.cols)
		{
			if (props->map.map[l][c] == '1')
				props->tilemap[l][c].img = props->images.wall;
			else if (props->map.map[l][c] == 'C')
				props->tilemap[l][c].img = props->images.colectible;
			else
				props->tilemap[l][c].img = props->images.floor;
		}
	}
}

void	load_tilemap(t_props *props)
{
	int	l;
	int	c;

	l = -1;
	while (++l < props->map.lines)
	{
		c = -1;
		while (++c < props->map.cols)
		{
			mlx_put_image_to_window(props->mlx.mlx_ptr, props->mlx.win_ptr,
				props->tilemap[l][c].img, TILES_SIZE * c, TILES_SIZE * l);
		}
	}
}

void	ready_map(t_props *props)
{
	open_image(props);
	props_map(props);
	load_tilemap(props);
	mlx_put_image_to_window(props->mlx.mlx_ptr, props->mlx.win_ptr,
		props->images.player, TILES_SIZE * props->player_y,
		TILES_SIZE * props->player_x);
}
