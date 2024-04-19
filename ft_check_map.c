/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:35:34 by merdal            #+#    #+#             */
/*   Updated: 2024/04/19 17:31:09 by merdal           ###   ########.fr       */
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

int	ft_wall_top_bottom(t_complete *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
			return (1);
		if (game->map[game->map_height][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_wall_sides(t_complete *game)
{
	int i;

	i = 0;
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width] != '1')
			return (1);
		i++;
	}
	return (0);
}



void	ft_check_map(t_complete *game)
{
	int amk = ft_wall_sides(game);
	printf("amk: %d\n", amk);
	print_map(game);
	printf("map_height: %d\n", game->map_height);
	printf("map_width: %d\n", game->map_width);
}