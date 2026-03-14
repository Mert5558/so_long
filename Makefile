# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 13:26:17 by merdal            #+#    #+#              #
#    Updated: 2024/05/07 12:36:30 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS =	src/so_long.c \
		src/ft_create_map.c \
		src/ft_check_walls.c \
		src/ft_check_characters.c \
		src/ft_place_images.c \
		src/ft_take_key_input.c \
		src/ft_move.c \
		src/ft_move_direction.c \
		src/ft_calloc.c \
		src/ft_free_everything.c \
		src/ft_check_path.c \

GNL = lib/GNL/src/get_next_line.c lib/GNL/src/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
LIBRARY = -ldl -lglfw -pthread -lm
MLX42 = MLX42
MLX_LIB = $(MLX42)/build/libmlx42.a
PRINTF = lib/printf
PRINTF_LIB = $(PRINTF)/libftprintf.a
INCLUDES = -I./src -I./lib/GNL/src -I./lib/printf/src -I./$(MLX42)/include
RM = rm -f

all: $(MLX_LIB) $(PRINTF_LIB) $(NAME)

MLX_URL = https://github.com/codam-coding-college/MLX42.git

$(MLX_LIB):
	if [ ! -d "$(MLX42)" ]; then git clone $(MLX_URL) $(MLX42); fi
	cd $(MLX42) && cmake -B build && cmake --build build -j4

$(PRINTF_LIB):
	make -C $(PRINTF)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(GNL) $(PRINTF_LIB) $(MLX_LIB) $(LIBRARY) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(PRINTF)

fclean: clean
	rm -rf $(MLX42)
	make fclean -C $(PRINTF)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re