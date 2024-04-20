# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 13:26:17 by merdal            #+#    #+#              #
#    Updated: 2024/04/20 16:24:20 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS =	so_long.c \
		ft_create_map.c \
		ft_check_walls.c \
		ft_check_characters.c \

GNL = GNL/*.c
OBJS = $(SRCS:.c=.o)
LIBRARY = ./MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX42 = MLX42/build/
RM = rm -f

all: minilibx $(NAME)

minilibx:
	make -C $(MLX42)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIBRARY) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	make clean -C $(MLX42)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re minilibx