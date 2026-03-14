/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:35:34 by merdal            #+#    #+#             */
/*   Updated: 2024/05/02 15:24:09 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_top_wall(t_complete *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_bottom_wall(t_complete *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[game->map_height - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_left_wall(t_complete *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_right_wall(t_complete *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][game->map_width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_walls(t_complete *game)
{
	if (ft_top_wall(game) == 1 || ft_bottom_wall(game) == 1)
	{
		ft_printf("Error\nMap is not surrounded by walls or not rectangular\n");
		exit(1);
	}
	if (ft_left_wall(game) == 1 || ft_right_wall(game) == 1)
	{
		ft_printf("Error\nMap is not surrounded by walls or not rectangular\n");
		exit(1);
	}
}
