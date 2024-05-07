/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:31:53 by merdal            #+#    #+#             */
/*   Updated: 2024/05/07 12:13:04 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_add_map_lines(t_complete *game, char *new_line)
{
	char	**temp_map;
	int		i;

	if (new_line == NULL)
		return (1);
	game->map_height++;
	temp_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (temp_map == NULL)
		return (1);
	i = 0;
	while (i < game->map_height - 1)
	{
		temp_map[i] = game->map[i];
		i++;
	}
	if (game->map != NULL)
		free(game->map);
	temp_map[game->map_height - 1] = new_line;
	temp_map[game->map_height] = NULL;
	game->map = temp_map;
	return (0);
}

int	ft_create_map(t_complete *game, char **argv)
{
	char	*new_line;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd == -1)
		return (0);
	while (1)
	{
		new_line = get_next_line(game->fd);
		if (ft_add_map_lines(game, new_line) == 1)
			break ;
	}
	close(game->fd);
	game->map_width = ft_strlen(game->map[0]) - 1;
	return (0);
}
