/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:41:44 by merdal            #+#    #+#             */
/*   Updated: 2024/05/07 12:19:28 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_complete *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_remainder(t_complete *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map_copy[i][j] == 'C' || game->map_copy[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_create_map_copy(t_complete *game)
{
	int	i;
	int	j;

	i = 0;
	game->map_copy = malloc(game->map_height * sizeof(char *));
	while (i < game->map_height)
	{
		game->map_copy[i] = malloc(game->map_width * sizeof(char));
		j = 0;
		while (j < game->map_width)
		{
			game->map_copy[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
}

void	flood_fill(t_complete *game, int x, int y)
{
	if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
		return ;
	if (game->map_copy[y][x] == '1')
		return ;
	if (game->map_copy[y][x] == '0' || game->map_copy[y][x] == 'C' ||
			game->map_copy[y][x] == 'E')
	{
		game->map_copy[y][x] = '1';
	}
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	ft_check_path(t_complete *game)
{
	int	i;

	ft_find_player(game);
	ft_create_map_copy(game);
	flood_fill(game, game->player_x, game->player_y);
	if (ft_check_remainder(game) == 1)
	{
		ft_printf("Error\nMap has no valid path\n");
		i = 0;
		while (i < game->map_height)
		{
			free(game->map_copy[i]);
			i++;
		}
		free(game->map_copy);
		exit(1);
	}
}
