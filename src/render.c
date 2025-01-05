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

void	free_loaded_images(t_slong *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

void	load_image_or_exit(t_slong *game, void **img, char *path)
{
	*img = mlx_xpm_file_to_image(game->mlx, path,
			&game->map_width, &game->map_height);
	if (!*img)
	{
		ft_printf("Error: Failed to load %s\n", path);
		free_loaded_images(game);
		exit_hook(game);
	}
}

void	load_images(t_slong *game)
{
	load_image_or_exit(game, (void **)&game->img_wall, "imgs/wall.xpm");
	load_image_or_exit(game, (void **)&game->img_floor, "imgs/sand.xpm");
	load_image_or_exit(game, (void **)&game->img_player, "imgs/pac.xpm");
	load_image_or_exit(game, (void **)&game->img_collectible, "imgs/coin.xpm");
	load_image_or_exit(game, (void **)&game->img_exit, "imgs/door2.xpm");
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
