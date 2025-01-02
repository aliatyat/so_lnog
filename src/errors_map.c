/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:05:21 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/30 21:05:23 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if the map is rectangular
void	validate_rectangular(char **map)
{
	int	width;
	int	y;

	y = 0;
	width = ft_strlen(map[0]);
	while (map[y])
	{
		if ((int)ft_strlen(map[y]) != width)
		{
			ft_printf("Error: Map is not rectangular\n");
			exit(EXIT_FAILURE);
		}
		y++;
	}
}

// Check if the map is surrounded by walls
void	validate_borders(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((y == 0 || !map[y + 1]) && map[y][x] != '1')
			{
				ft_printf("Error: Top/Bottom border is not enclosed\n");
				exit(EXIT_FAILURE);
			}
			if ((x == 0 || !map[y][x + 1]) && map[y][x] != '1')
			{
				ft_printf("Error: Side border is not enclosed\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

// General map validation function
void	validate_map(char **map)
{
	validate_rectangular(map);
	validate_borders(map);
}
