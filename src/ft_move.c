/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:45:07 by merdal            #+#    #+#             */
/*   Updated: 2024/05/02 14:35:54 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_complete *game, int x, int y)
{
	if (game->map[y][x] == 'E')
		game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
	game->player_image->instances->x = x * 64;
	game->player_image->instances->y = y * 64;
}

void	ft_game_finished(t_complete *game, int x, int y)
{
	ft_move_player(game, x, y);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Game finished!\n");
	exit(0);
}

void	ft_remove_coin(t_complete *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->c_total)
	{
		if (game->collectable_image->instances[i].x == x * 64
			&& game->collectable_image->instances[i].y == y * 64)
		{
			game->collectable_image->instances[i].enabled = false;
			game->map[y][x] = '0';
			game->c_counter--;
			break ;
		}
		i++;
	}
}

void	ft_check_coin(t_complete *game, int x, int y)
{
	ft_remove_coin(game, x, y);
	ft_move_player(game, x, y);
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("Coins left: %d\n", game->c_counter);
}

void	ft_move(t_complete *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->c_counter == 0)
	{
		ft_game_finished(game, x, y);
		return ;
	}
	if (game->map[y][x] == '0')
	{
		ft_move_player(game, x, y);
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
	if (game->map[y][x] == 'C')
	{
		ft_check_coin(game, x, y);
	}
	if (game->map[y][x] == 'P')
	{
		ft_move_player(game, x, y);
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}
