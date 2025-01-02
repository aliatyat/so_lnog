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

// Handle collectible and exit logic
void	handle_special_tile(t_slong *game, int new_x, int new_y)
{
	int	i;

	i = 2;
	if (game->map_data[new_y][new_x] == 'C')
	{
		ft_printf("Collected an item!\n");
		game->map_data[new_y][new_x] = '0';
		game->collected_items++;
		ft_printf("%d"
			"You reached the items 1!\n",
			game->collected_items);
	}
	if (game->map_data[new_y][new_x] == 'E')
	{
		if (game->collected_items == i)
		{
			ft_printf("You reached the exit!\n");
			exit_hook(game);
		}
		else
		{
			ft_printf("Collect all items before exiting!\n");
		}
	}
}
// Move player with collision detection

// Handle collectible or exit tile interactions
// int	handle_tile_interaction(t_slong *game, int new_x, int new_y)
// {
// 	if (game->map_data[new_y][new_x] == 'C')
// 	{
// 		ft_printf("Collected an item!\n");
// 		game->map_data[new_y][new_x] = '0';
// 		return (1);
// 	}
// 	if (game->map_data[new_y][new_x] == 'E')
// 	{
// 		if (all_coins_collected(game))
// 		{
// 			ft_printf("You reached the exit! Congratulations!\n");
// 			exit_hook(game);
// 		}
// 		else
// 		{
// 			ft_printf("You must collect all coins before exiting!\n");
// 			return (0);
// 		}
// 	}
// 	return (1);
// }

// // Move player with collision detection
// void	move_player(t_slong *game, int dx, int dy)
// {
// 	int	new_x;
// 	int	new_y;

// 	new_x = game->player_x + dx;
// 	new_y = game->player_y + dy;
// 	if (!can_move_to(game, new_x, new_y))
// 		return ;
// 	if (!handle_tile_interaction(game, new_x, new_y))
// 		return ;
// 	game->map_data[game->player_y][game->player_x] = '0';
// 	game->map_data[new_y][new_x] = 'P';
// 	game->player_x = new_x;
// 	game->player_y = new_y;
// 	mlx_clear_window(game->mlx, game->win);
// 	render_map(game);
// }

// int	keys_hook(int keycode, t_slong *game)
// {
// 	if (keycode == XK_Escape)
// 		exit_hook(game);
// 	if (keycode == XK_w || keycode == XK_Up)
// 		move_player(game, 0, -1);
// 	if (keycode == XK_s || keycode == XK_Down)
// 		move_player(game, 0, 1);
// 	if (keycode == XK_d || keycode == XK_Right)
// 		move_player(game, 1, 0);
// 	if (keycode == XK_a || keycode == XK_Left)
// 		move_player(game, -1, 0);
// 	mlx_clear_window(game->mlx, game->win);
// 	render_map(game);
// 	return (0);
// }

// int	exit_hook(t_slong *game)
// {
// 	if (game)
// 	{
// 		printf("Exiting game...\n");
// 		if (game->win)
// 		{
// 			mlx_destroy_window(game->mlx, game->win);
// 			game->win = NULL;
// 		}
// 		if (game->mlx)
// 		{
// 			mlx_destroy_display(game->mlx);
// 			free(game->mlx);
// 			game->mlx = NULL;
// 		}
// 		free_map(game->map_data);
// 	}
// 	exit(EXIT_SUCCESS);
// 	return (0);
// }
