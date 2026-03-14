/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:10:59 by merdal            #+#    #+#             */
/*   Updated: 2024/04/29 16:49:06 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_complete *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '1')
		return ;
	ft_move(game, game->player_x, game->player_y - 1);
}

void	ft_move_down(t_complete *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '1')
		return ;
	ft_move(game, game->player_x, game->player_y + 1);
}

void	ft_move_left(t_complete *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '1')
		return ;
	ft_move(game, game->player_x - 1, game->player_y);
}

void	ft_move_right(t_complete *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '1')
		return ;
	ft_move(game, game->player_x + 1, game->player_y);
}
