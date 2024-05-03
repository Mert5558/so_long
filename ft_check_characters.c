/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:33:10 by merdal            #+#    #+#             */
/*   Updated: 2024/05/03 12:12:41 by merdal           ###   ########.fr       */
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
	game->c_total = count;
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
	int	game_exit;
	int	player;

	collectible = ft_check_collectible(game);
	game_exit = ft_check_exit(game);
	player = ft_check_player(game);
	if (collectible == 0 || game_exit == 0 || player == 0)
	{
		ft_printf("Error\n");
		ft_printf("Map must have at least 1 collectible,");
		ft_printf(" 1 exit and 1 player\n");
		exit(1);
	}
	if (game_exit > 1 || player > 1)
	{
		ft_printf("Error\n");
		ft_printf("Map must have only 1 exit and 1 player\n");
		exit(1);
	}
}
