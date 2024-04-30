/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_key_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:05:06 by merdal            #+#    #+#             */
/*   Updated: 2024/04/29 16:57:53 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_take_key_input(mlx_key_data_t keydata, void *param)
{
	t_complete	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlxpointer);
	if (keydata.key == MLX_KEY_W)
		ft_move_up(game);
	if (keydata.key == MLX_KEY_A)
		ft_move_left(game);
	if (keydata.key == MLX_KEY_S)
		ft_move_down(game);
	if (keydata.key == MLX_KEY_D)
		ft_move_right(game);
}
