/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:39:56 by merdal            #+#    #+#             */
/*   Updated: 2024/04/26 14:53:10 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./GNL/get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define WIDTH 1000
# define HEIGHT 400

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
	void	*winpointer;
	void	*mlxpointer;

	mlx_texture_t	*player_texture;
	mlx_texture_t	*collectable_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_texture_t	*exit_texture;

	mlx_image_t		*player_image;
	mlx_image_t		*collectable_image;
	mlx_image_t		*wall_image;
	mlx_image_t		*floor_image;
	mlx_image_t		*exit_image;

}	t_complete;

int		ft_create_map(t_complete *game, char **argv);
void	ft_check_walls(t_complete *game);
void	ft_check_characters(t_complete *game);
void	ft_load_images(t_complete *game);
void	ft_place_images(t_complete *game);
void	ft_place_images_2(t_complete *game);
void	ft_texture_to_image(t_complete *game);

#endif