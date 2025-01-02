/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eve.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:38:43 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/31 16:39:05 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Validate player movement
int	can_move_to(t_slong *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map_width
		|| new_y >= game->map_height)
		return (0);
	if (game->map_data[new_y][new_x] == '1')
		return (0);
	return (1);
}

// Check if all coins are collected
int	all_coins_collected(t_slong *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_data[y])
	{
		x = 0;
		while (game->map_data[y][x])
		{
			if (game->map_data[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
