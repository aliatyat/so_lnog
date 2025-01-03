/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:49:50 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/31 16:50:58 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Open the map file and initialize temporary buffer
void	read_for_fd(char *map_file, int *fd, char **tmp)
{
	if (!validate_file_extension(map_file))
		exit(EXIT_FAILURE);
	*fd = open(map_file, O_RDONLY);
	if (*fd == -1)
	{
		ft_printf("Error: open() failed\n");
		exit(EXIT_FAILURE);
	}
	*tmp = ft_strdup("");
	if (!*tmp)
	{
		ft_printf("Error: memory allocation failed\n");
		close(*fd);
		exit(EXIT_FAILURE);
	}
}

// Read lines from the map file
void	read_map_lines(int fd, char **tmp)
{
	char	*line;
	char	*new_tmp;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\0')
		{
			free(line);
			break ;
		}
		new_tmp = ft_strjoin(*tmp, line);
		free(*tmp);
		free(line);
		if (!new_tmp)
		{
			ft_printf("Error: memory allocation failed\n");
			close(fd);
			exit(EXIT_FAILURE);
		}
		*tmp = new_tmp;
		line = get_next_line(fd);
	}
}

// Validate that the map is not empty
void	validate_map_not_empty(char *tmp, int fd)
{
	if (!tmp || tmp[0] == '\0')
	{
		ft_printf("Error: empty map\n");
		free(tmp);
		close(fd);
		exit(EXIT_FAILURE);
	}
}

// Validate that there are no empty lines in the map
void	validate_no_empty_lines(char *tmp, int fd)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if ((tmp[i] == '\n' && tmp[i + 1] == '\n')
			|| (i == 0 && tmp[i] == '\n'))
		{
			ft_printf("Error: map contains empty lines\n");
			free(tmp);
			close(fd);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	validate_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
	{
		ft_printf("Error: Invalid file extension.\n");
		return (0);
	}
	return (1);
}
