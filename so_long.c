/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merdal <merdal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:39:34 by merdal            #+#    #+#             */
/*   Updated: 2024/04/19 16:11:21 by merdal           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_complete	game;
	
	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	ft_create_map(&game, argv);
	ft_check_map(&game);
}
