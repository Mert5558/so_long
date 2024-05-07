# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 13:26:17 by merdal            #+#    #+#              #
#    Updated: 2024/05/04 12:50:34 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS =	so_long.c \
        ft_create_map.c \
        ft_check_walls.c \
        ft_check_characters.c \
        ft_place_images.c \
        ft_take_key_input.c \
        ft_move.c \
        ft_move_direction.c \
        ft_calloc.c \
		ft_free_everything.c \
		ft_check_path.c \

GNL = GNL/*.c
OBJS = $(SRCS:.c=.o)
LIBRARY = -ldl -lglfw -pthread -lm
MLX42 = MLX42
MLX_LIB = $(MLX42)/build/libmlx42.a
PRINTF = printf
PRINTF_LIB = printf/libftprintf.a
RM = rm -f

all: $(MLX_LIB) $(PRINTF_LIB) $(NAME)

MLX_URL = https://github.com/codam-coding-college/MLX42.git

$(MLX_LIB):
	if [ ! -d "$(MLX42)" ]; then git clone $(MLX_URL) $(MLX42); fi
	cd $(MLX42) && cmake -B build && cmake --build build -j4

$(PRINTF_LIB):
	make -C $(PRINTF)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(PRINTF_LIB) $(MLX_LIB) $(LIBRARY) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(PRINTF)

fclean: clean
	rm -rf $(MLX42)
	make fclean -C $(PRINTF)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re