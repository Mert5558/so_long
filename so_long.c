/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:39:34 by merdal            #+#    #+#             */
/*   Updated: 2024/04/26 15:26:53 by merdal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *mem, int value, size_t n)
{
	unsigned char	byte_value;
	unsigned char	*dest;
	size_t			i;

	byte_value = (unsigned char)value;
	dest = (unsigned char *)mem;
	i = 0;
	while (i < n)
	{
		dest[i] = byte_value;
		i++;
	}
	return (mem);
}

void	ft_init(t_complete *game)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlxpointer = mlx_init(game->map_height * 64, game->map_width * 64,
			"so_long", true);
	if (!game->mlxpointer)
	{
		free(game->mlxpointer);
		printf("Error\nFailure in mlx_init!\n");
	}
	ft_load_images(game);
	ft_place_images(game);
	ft_place_images(game);
}

int	main(int argc, char **argv)
{
	t_complete	*game;
	
	if (argc != 2)
		return (0);
	game = calloc(1, sizeof(t_complete));
	if (!game)
		return (1);
	ft_create_map(game, argv);
	ft_check_walls(game);
	ft_check_characters(game);
	game->mlxpointer = mlx_init(game->map_width * 64, game->map_height *64, "so_long", true);
	ft_load_images(game);
	ft_texture_to_image(game);
	ft_place_images(game);
	ft_place_images_2(game);
	
	return (0);
}