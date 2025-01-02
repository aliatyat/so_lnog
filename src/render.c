/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:33:32 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/30 16:33:33 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_slong *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm",
			&game->map_width, &game->map_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "imgs/sand.xpm",
			&game->map_width, &game->map_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "imgs/pac.xpm",
			&game->map_width, &game->map_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "imgs/coin.xpm",
			&game->map_width, &game->map_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/door2.xpm",
			&game->map_width, &game->map_height);
}

void	render_player(t_slong *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->player_x * 50, game->player_y * 50);
}

void	render_map(t_slong *game)
{
	int		y;
	int		x;
	void	*img;

	y = 0;
	while (game->map_data[y])
	{
		x = 0;
		while (game->map_data[y][x])
		{
			img = game->img_floor;
			if (game->map_data[y][x] == '1')
				img = game->img_wall;
			else if (game->map_data[y][x] == 'C')
				img = game->img_collectible;
			else if (game->map_data[y][x] == 'E')
				img = game->img_exit;
			mlx_put_image_to_window(game->mlx, game->win, img, x * 50, y * 50);
			x++;
		}
		y++;
	}
	render_player(game);
}
