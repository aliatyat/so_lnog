/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:18:18 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/30 16:18:48 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Free allocated memory for map data
void	free_map(char **map)
{
	int	i;
	int	rows;

	rows = 0;
	if (!map)
		return ;
	i = -1;
	while (map[++i])
		rows++;
	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// Initialize game structure
void	init_game(t_slong *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: MLX initialization failed\n");
		free_map (game->map_data);
		exit(EXIT_FAILURE);
	}
}

// Set window dimensions based on map size
void	set_window_size(t_slong *game)
{
	game->map_width = 50 * ft_strlen(game->map_data[0]);
	game->map_height = 50 * ft_strlen_2d(game->map_data);
	game->win = mlx_new_window(game->mlx, game->map_width, game->map_height,
			"so_long");
	if (!game->win)
	{
		ft_printf("Error: Window creation failed\n");
		mlx_destroy_display(game->mlx);
		free (game->mlx);
		free_map(game->map_data);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_slong	game;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long <map_file>\n");
		return (EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_slong));
	save_for_map(av[1], &game);
	init_player_position(&game);
	init_game(&game);
	set_window_size(&game);
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, keys_hook, &game);
	mlx_hook(game.win, 17, 0, exit_hook, &game);
	mlx_loop(game.mlx);
	free_map(game.map_data);
	return (0);
}
