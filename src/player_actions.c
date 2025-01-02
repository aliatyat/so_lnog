/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:37:34 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/31 16:37:36 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Handle collectible or exit tile interactions
int	handle_tile_interaction(t_slong *game, int new_x, int new_y)
{
	if (game->map_data[new_y][new_x] == 'C')
	{
		ft_printf("Collected an item!\n");
		game->map_data[new_y][new_x] = '0';
		return (1);
	}
	if (game->map_data[new_y][new_x] == 'E')
	{
		if (all_coins_collected(game))
		{
			ft_printf("You reached the exit! Congratulations!\n");
			exit_hook(game);
		}
		else
		{
			ft_printf("You must collect all coins before exiting!\n");
			return (1);
		}
	}
	return (1);
}

// Move player with collision detection
void	move_player(t_slong *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!can_move_to(game, new_x, new_y))
		return ;
	if (!handle_tile_interaction(game, new_x, new_y))
		return ;
	if (game->map_data[game->player_y][game->player_x] != 'E')
		game->map_data[game->player_y][game->player_x] = '0';
	if (game->map_data[new_y][new_x] != 'E')
		game->map_data[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

int	keys_hook(int keycode, t_slong *game)
{
	if (keycode == XK_Escape)
		exit_hook(game);
	else
		handle_movement(keycode, game);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}

// Free Images Leaks
void	free_res(t_slong *game)
{
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_collectible);
}

int	exit_hook(t_slong *game)
{
	if (game)
	{
		printf("Exiting game...\n");
		free_res(game);
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
			game->mlx = NULL;
		}
		free_map(game->map_data);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
