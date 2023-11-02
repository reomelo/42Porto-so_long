/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:06:08 by riolivei          #+#    #+#             */
/*   Updated: 2023/09/26 19:05:06 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_errors(char *message)
{
	write(1, message, ft_strlen(message));
	exit(0);
}

void	count_steps(t_props *props)
{
	props->steps++;
	write(1, "Steps: ", 7);
	ft_putnbr_fd(props->steps, 1);
	write(1, "\n", 1);
}

int	close_program(void)
{
	exit(1);
}

void	hooks(t_props *props)
{
	mlx_hook(props->mlx.win_ptr, 2, 1, on_key_press, props);
	mlx_hook(props->mlx.win_ptr, 17, (1L << 2), close_program, props);
	mlx_loop(props->mlx.mlx_ptr);
}
