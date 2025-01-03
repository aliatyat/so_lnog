/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:15 by alalauty          #+#    #+#             */
/*   Updated: 2024/10/23 13:58:47 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_slong
{
	char	**map_data;
	int		map_width;
	int		map_height;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		collected_items;
	int		total_collectibles;
	int		found_exit;
	int		collected;
	int		player;
	int		exitd;
	int		collectible;
	int		required_collectibles;
	int		movement_count;
}			t_slong;

// Map Functions
void		save_for_map(char *map_file, t_slong *game);
//int			ft_strlen_2d(char **map);
void		read_map_lines(int fd, char **tmp);
void		read_for_fd(char *map_file, int *fd, char **tmp);

// Rendering Functions
void		load_images(t_slong *game);
void		render_map(t_slong *game);

// Event Functions
int			keys_hook(int keycode, t_slong *game);
void		init_player_position(t_slong *game);
int			exit_hook(t_slong *game);
int			all_coins_collected(t_slong *game);
int			can_move_to(t_slong *game, int new_x, int new_y);

// Map Validation Functions
int			validate_file_extension(char *filename);
void		validate_map(char **map);
void		validate_rectangular(char **map);
void		validate_borders(char **map);
void		validate_components(char **map, int fd);
void		validate_map_not_empty(char *tmp, int fd);
void		validate_no_empty_lines(char *tmp, int fd);
void		validate_map_characters(char **map);

//Validate_path
void		validate_path(t_slong *game);
void		flood_fill(char **map, int x, int y, t_slong *game);
int			find_position(t_slong *game);
int			count_collectibles(char **map);
char		**copy_map(char **map);

// Utility Functions
void		free_map(char **map);

//Player Movement
void		count_player_movement(t_slong *game);
void		handle_movement(int keycode, t_slong *game);
void		move_player(t_slong *game, int dx, int dy);

#endif
