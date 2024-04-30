/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_key_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:05:06 by merdal            #+#    #+#             */
/*   Updated: 2024/04/30 13:26:06 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_take_key_input(mlx_key_data_t keydata, void *param)
{
	t_complete	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlxpointer);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_move_up(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_move_left(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_move_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_move_right(game);
}
