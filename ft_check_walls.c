/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:35:34 by merdal            #+#    #+#             */
/*   Updated: 2024/04/20 15:47:11 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_complete *game) {
    for (int i = 0; i < game->map_height; i++) {
        for (int j = 0; j < game->map_width; j++) {
            printf("%c ", game->map[i][j]);
        }
        printf("\n");
    }
}

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

int ft_bottom_wall(t_complete *game)
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
	int i;

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
	int i;

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
		write(1, "Error\nMap is not surrounded by walls\n", 37);
		//exit;
	}

	if (ft_left_wall(game) == 1 || ft_right_wall(game) == 1)
	{
		write(1, "Error\nMap is not surrounded by walls\n", 37);
		//exit;
	}
}