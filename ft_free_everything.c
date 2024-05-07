/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:49:07 by merdal            #+#    #+#             */
/*   Updated: 2024/05/07 12:21:43 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_everything(t_complete *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	i = 0;
	free(game->map);
	mlx_delete_texture(game->player_texture);
	mlx_delete_texture(game->collectable_texture);
	mlx_delete_texture(game->wall_texture);
	mlx_delete_texture(game->floor_texture);
	mlx_delete_texture(game->exit_texture);
	mlx_delete_image(game->mlxpointer, game->player_image);
	mlx_delete_image(game->mlxpointer, game->collectable_image);
	mlx_delete_image(game->mlxpointer, game->wall_image);
	mlx_delete_image(game->mlxpointer, game->floor_image);
	mlx_delete_image(game->mlxpointer, game->exit_image);
	mlx_terminate(game->mlxpointer);
	free(game);
}
