/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:39:56 by merdal            #+#    #+#             */
/*   Updated: 2024/04/19 16:08:45 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./GNL/get_next_line.h"
# include "./minilibx/mlx.h"

typedef struct t_start
{
	int		fd;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		map_height;
	int		map_width;
	int		x_axis;
	int		y_axis;
	int		collectables;
	int		counter;

	char	**map;

	void	*player;
	void	*collectable;
	void	*barrier;
	void	*floor;
	void	*exit;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		ft_create_map(t_complete *game, char **argv);
void	ft_check_map(t_complete *game);


#endif