/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:45:07 by merdal            #+#    #+#             */
/*   Updated: 2024/04/29 17:45:37 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_complete *game, int x, int y)
{
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
}

void	ft_game_finished(t_complete *game, int x, int y)
{
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	write(1, "You won!\n", 9);
	ft_move_player(game, x, y);
	exit(0);
}

// void	ft_remove_coin(t_complete *game, int x, int y)
// {
	
// }

void	ft_check_coin(t_complete *game, int x, int y)
{
	game->c_counter--;
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	write(1, "collectables left: \n", 21);
	ft_putnbr(game->c_counter);
	ft_move_player(game, x, y);
	//ft_remove_coin(game, x, y);
}

void	ft_move(t_complete *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->c_counter == 0)
	{
		ft_game_finished(game, x ,y);
	}
	if (game->map[y][x] == 'C')
	{
		ft_check_coin(game, x, y);
	}
	else
	{
		ft_move_player(game, x, y);
		game->moves++;
		write(1, "Moves: ", 7);
		ft_putnbr(game->moves);
		write(1, "\n", 1);
	}
}
