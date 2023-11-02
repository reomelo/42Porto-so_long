# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:15:32 by riolivei          #+#    #+#              #
#    Updated: 2022/12/03 16:11:03 by riolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
MLXFLAGS = -L ./mlx -lmlx -Ilmlx -lXext -lX11

SRCS = src/main.c src/find_path.c src/map.c src/game.c src/itoa.c src/hooks.c\
		src/path_functions.c src/path.c src/split.c src/game_utils.c src/putnbr.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
				$(MAKE) --no-print-directory -C ./mlx
				$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)
                
clean:
				${RM} ${OBJS}

fclean: clean
				${RM} ${NAME}

re: fclean all

.PHONY: all clear fclean re