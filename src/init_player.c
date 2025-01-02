/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:54:36 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/31 16:54:47 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialize the player's starting position
void	init_player_position(t_slong *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_data[y])
	{
		x = 0;
		while (game->map_data[y][x])
		{
			if (game->map_data[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_printf("Error: No player start position found\n");
	exit(EXIT_FAILURE);
}

// Increment and display player movement count
void	count_player_movement(t_slong *game)
{
	game->movement_count++;
	ft_printf("Player movements: %d\n", game->movement_count);
}
