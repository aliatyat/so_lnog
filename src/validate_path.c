/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 21:23:29 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/31 21:23:41 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Recursive flood fill to mark reachable positions
void	flood_fill(char **map, int x, int y, t_slong *game)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x])
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		game->found_exit++;
	if (map[y][x] == 'C')
		game->collected++;
	map[y][x] = '1';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

// Create a temporary copy of the map row by row
char	**copy_map_rows(char **map, char **copy, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

// Create a temporary copy of the map
char	**copy_map(char **map)
{
	int		rows;
	char	**copy;

	rows = 0;
	while (map[rows])
		rows++;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	return (copy_map_rows(map, copy, rows));
}

// Count total collectibles on the map
int	count_collectibles(char **map)
{
	int	y;
	int	x;
	int	collectibles;

	y = 0;
	collectibles = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}

int	find_position(t_slong *game)
{
	int	y;
	int	x;
	int	collectibles;

	y = 0;
	collectibles = 0;
	while (game->map_data[y])
	{
		x = 0;
		while (game->map_data[y][x])
		{
			if (game->map_data[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return (EXIT_SUCCESS);
			}
			x++;
		}
		y++;
	}
	return (collectibles);
}
