/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:06:01 by alalauty          #+#    #+#             */
/*   Updated: 2025/01/03 17:06:05 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strlen_2d(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}
