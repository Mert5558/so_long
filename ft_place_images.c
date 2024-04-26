/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:10:37 by merdal            #+#    #+#             */
/*   Updated: 2024/04/26 14:52:57 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_images(t_complete *game)
{
	game->wall_texture = mlx_load_png("./images/wall.png");
	if (!game->wall_texture)
		write(1, "Error loading wall image\n", 25);
	game->floor_texture = mlx_load_png("./images/floor.png");
	if (!game->floor_texture)
		write(1, "Error loading floor image\n", 26);
	game->collectable_texture = mlx_load_png("./images/coin.png");
	if (!game->collectable_texture)
		write(1, "Error loading collectable image\n", 31);
	game->player_texture = mlx_load_png("./images/player.png");
	if (!game->player_texture)
		write(1, "Error loading player image\n", 27);
	game->exit_texture = mlx_load_png("./images/exit.png");
	if (!game->exit_texture)
		write(1, "Error loading exit image\n", 25);
}

void	ft_texture_to_image(t_complete *game)
{
	game->wall_image = mlx_texture_to_image(game->mlxpointer, game->wall_texture);
		if (!game->wall_image)
			write(1, "Error converting wall tex to img", 32);
	game->floor_image = mlx_texture_to_image(game->mlxpointer, game->floor_texture);
		if (!game->floor_image)
			write(1, "Error converting floor tex to img", 33);
	game->collectable_image = mlx_texture_to_image(game->mlxpointer, game->collectable_texture);
		if (!game->collectable_image)
			write(1, "Error converting collectable tex to img", 38);
	game->player_image = mlx_texture_to_image(game->mlxpointer, game->player_texture);
		if (!game->player_image)
			write(1, "Error converting player tex to img", 34);
	game->exit_image = mlx_texture_to_image(game->mlxpointer, game->exit_texture);
		if (!game->exit_image)
			write(1, "Error converting exit tex to img", 32);
}

void	ft_place_images(t_complete *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlxpointer, game->wall_image,
					x * 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlxpointer, game->floor_image,
					x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlxpointer, game->collectable_image,
					x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_place_images_2(t_complete *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlxpointer, game->player_image,
					x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlxpointer, game->exit_image,
					x * 64, y * 64);
			x++;
		}
		y++;
	}
}
