/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <riolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:08:19 by riolivei          #+#    #+#             */
/*   Updated: 2023/11/02 16:44:16 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "keys.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define TILES_SIZE 64
# define FLOOR_TILE "assets/floor.xpm"
# define WALL_TILE "assets/wall.xpm"
# define PLAYER_TILE "assets/player.xpm"
# define PLAYER_LEFT_TILE "assets/player_left.xpm"
# define PLAYER_RIGHT_TILE "assets/player_right.xpm"
# define COLECTIBLE_TILE "assets/colectible.xpm"
# define EXIT_TILE "assets/exit.xpm"

typedef struct s_map{
	char	**map;
	char	*buff;
	int		lines;
	int		cols;
	int		count;
	bool	exit_ok;
}				t_map;

typedef struct s_images
{
	int		current_player_idle;
	bool	is_left;

	void	*floor;
	void	*wall;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*colectible;
	void	*exit;
}				t_images;

typedef struct s_tilemap
{
	void	*img;
}				t_tilemap;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

typedef struct s_props{
	struct s_mlx		mlx;
	struct s_images		images;
	struct s_tilemap	**tilemap;
	t_map				map;

	int					steps;
	int					player_x;
	int					player_y;
	int					exit_x;
	int					exit_y;
}				t_props;

// MAIN.C
int		main(int argc, const char **argv);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int start, int len);
void	initiate(t_props *props);
int		lines_len(t_props *props);

// MAP.C
int		validate_map(const char *argv, t_props *props);
int		val_chars(t_props *props);
int		chars_count(t_props *props);
int		map_struct(t_props *props);
int		map_walls(t_props *props, int lines);

// PATH.C
char	*new_line(int cols);
int		path(t_props *props);
int		len_cols(char *buff);
int		validate_extension(const char *argv);
void	positions(t_props *props);

// PATH_FUNCTIONS.C
int		colect(t_props *props);
int		line_counter(t_props *props);

// FIND_PATH.C
int		find_path(char **sol, t_props *props, int l, int c);
bool	is_valid(t_props *props, int l, int c);
char	**solution(int lines, int cols);

// SPLIT.C
int		count_words(char *s, char c);
int		count_letters(char *s, char c, int i);
char	**ft_split(t_props *props, char c);

// GAME.C
void	handle_errors(char *message);
void	open_image(t_props *props);
void	props_map(t_props *props);
void	load_tilemap(t_props *props);
void	ready_map(t_props *props);

// GAME_UTILS.C
void	handle_errors(char *message);
void	count_steps(t_props *props);
void	hooks(t_props *props);

// HOOKS.C
void	check_collison(t_props *props);
void	player_movement(t_props *props, bool horizontal, int speed);
void	reload(t_props	*props, void *current_player);
int		on_key_press(int key_code, t_props *props);

// ITOA.C
char	*ft_itoa(int n);
int		is_negative(int n);
int		num_digits(int n);

// PUTNBR.C
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif