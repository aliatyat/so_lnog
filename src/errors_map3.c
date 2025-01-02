/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:34:20 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/31 18:34:49 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Count player, exit, and collectible components on the map
void	count_components(char **map, int *player, int *exitd, int *collectible)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				(*player)++;
			else if (map[y][x] == 'E')
				(*exitd)++;
			else if (map[y][x] == 'C')
				(*collectible)++;
			x++;
		}
		y++;
	}
}

// Validate if map components meet the required conditions
void	check_component_counts(int player, int exitd, int collectible, int fd)
{
	if (player != 1 || exitd != 1 || collectible < 1)
	{
		ft_printf("Error: Invalid map components (P:1, E:1, C:>=1 required)\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
}

// Validate all map components
void	validate_components(char **map, int fd)
{
	int	player;
	int	exitd;
	int	collectible;

	player = 0;
	exitd = 0;
	collectible = 0;
	count_components(map, &player, &exitd, &collectible);
	check_component_counts(player, exitd, collectible, fd);
}

// Validate the path from player to exit and collectibles
void	validate_path(t_slong *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map_data);
	if (!map_copy)
	{
		ft_printf("Error: Failed to allocate memory for path validation\n");
		exit(EXIT_FAILURE);
	}
	game->found_exit = 0;
	game->collected = 0;
	game->required_collectibles = count_collectibles(game->map_data);
	find_position(game);
	flood_fill(map_copy, game->player_x, game->player_y, game);
	if (game->found_exit != 1 || game->collected != game->required_collectibles)
	{
		ft_printf("Error: Invalid path \n");
		free_map(map_copy);
		free_map(game->map_data);
		exit(EXIT_FAILURE);
	}
	free_map(map_copy);
}
