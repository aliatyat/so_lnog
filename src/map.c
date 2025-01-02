/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:34:41 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/30 16:34:43 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check if the map is empty or contains empty lines between rows
void	check_map_empty(t_slong *game, char *tmp, int fd)
{
	validate_map_not_empty(tmp, fd);
	validate_no_empty_lines(tmp, fd);
	game->map_data = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	if (!game->map_data)
	{
		ft_printf("Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
}

// Validate if the map adheres to the rules
void	validate_full_map(t_slong *game, int fd)
{
	validate_rectangular(game->map_data);
	validate_borders(game->map_data);
	validate_components(game->map_data, fd);
	validate_path(game);
}

// Save the map into the game structure
void	save_for_map(char *map_file, t_slong *game)
{
	int		fd;
	char	*tmp;

	read_for_fd(map_file, &fd, &tmp);
	read_map_lines(fd, &tmp);
	check_map_empty(game, tmp, fd);
	validate_full_map(game, fd);
}
