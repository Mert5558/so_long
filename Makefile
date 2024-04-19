# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merdal <merdal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 13:26:17 by merdal            #+#    #+#              #
#    Updated: 2024/04/19 16:09:00 by merdal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS =	so_long.c \
		ft_create_map.c \
		ft_check_map.c \

GNL = GNL/*.c
OBJS = $(SRCS:.c=.o)
LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx/
RM = rm -f

all: minilibx $(NAME)

minilibx:
	make -C $(MINILIBX)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIBRARY) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	make clean -C $(MINILIBX)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re minilibx