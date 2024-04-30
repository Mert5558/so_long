/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:39:34 by merdal            #+#    #+#             */
/*   Updated: 2024/04/30 15:52:57 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_complete	*game;

	if (argc != 2)
		return (0);
	game = calloc(1, sizeof(t_complete));
	if (!game)
		return (1);
	ft_create_map(game, argv);
	ft_check_walls(game);
	ft_check_characters(game);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlxpointer = mlx_init(game->map_width * 64,
			game->map_height * 64, "so_long", true);
	ft_load_images(game);
	ft_texture_to_image(game);
	ft_place_floor(game);
	ft_place_images(game);
	ft_place_player(game);
	mlx_key_hook(game->mlxpointer, ft_take_key_input, game);
	mlx_loop(game->mlxpointer);
	return (0);
}
