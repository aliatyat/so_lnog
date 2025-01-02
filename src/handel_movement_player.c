/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_movement_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:23:50 by alalauty          #+#    #+#             */
/*   Updated: 2025/01/01 21:24:34 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_slong *game)
{
	if (game->map_data[game->player_y - 1][game->player_x] != '1')
	{
		move_player(game, 0, -1);
		count_player_movement(game);
	}
}

void	move_down(t_slong *game)
{
	if (game->map_data[game->player_y + 1][game->player_x] != '1')
	{
		move_player(game, 0, 1);
		count_player_movement(game);
	}
}

void	move_left(t_slong *game)
{
	if (game->map_data[game->player_y][game->player_x - 1] != '1')
	{
		move_player(game, -1, 0);
		count_player_movement(game);
	}
}

void	move_right(t_slong *game)
{
	if (game->map_data[game->player_y][game->player_x + 1] != '1')
	{
		move_player(game, 1, 0);
		count_player_movement(game);
	}
}

void	handle_movement(int keycode, t_slong *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		move_up(game);
	else if (keycode == XK_s || keycode == XK_Down)
		move_down(game);
	else if (keycode == XK_a || keycode == XK_Left)
		move_left(game);
	else if (keycode == XK_d || keycode == XK_Right)
		move_right(game);
}
