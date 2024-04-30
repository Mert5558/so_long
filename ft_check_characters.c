/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:33:10 by merdal            #+#    #+#             */
/*   Updated: 2024/04/29 16:44:08 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_collectible(t_complete *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	game->c_counter = count;
	return (count);
}

int	ft_check_exit(t_complete *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_check_player(t_complete *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_check_characters(t_complete *game)
{
	int	collectible;
	int	exit;
	int	player;

	collectible = ft_check_collectible(game);
	exit = ft_check_exit(game);
	player = ft_check_player(game);
	if (collectible == 0 || exit == 0 || player == 0)
	{
		write(1, "Error\n", 6);
		write(1, "Map must have at least 1 coin, 1 exit and 1 player\n", 59);
	}
	if (exit > 1 || player > 1)
	{
		write(1, "Error\n", 6);
		write(1, "Map must have only one exit and one player\n", 45);
	}
}
