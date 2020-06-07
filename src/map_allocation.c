/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 05:49:02 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/07 02:03:10 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*map_to_str(int fd)
{
	char	*map;
	char	*tmp;
	char	*line;

	map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		tmp = map;
		map = ft_strjoin(map, "\n");
		free(tmp);
		free(line);
	}
	free(line);
	return (map);
}

void	end(int x, int y, t_stru *stru)
{
	stru->map[y] = NULL;
	stru->map_height = y;
	stru->map_width = x;
}

int		alloc_y(char *map, t_stru *stru)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			y++;
		i++;
	}
	if (!(stru->map = malloc(sizeof(char *) * (y + 1))))
		return (-1);
	return (y);
}

int		alloc_x(char *map, t_stru *stru, int y)
{
	int i;
	int x;
	int	x_max;

	i = 0;
	x = 0;
	x_max = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (x > x_max)
				x_max = x;
			x = 0;
		}
		x++;
		i++;
	}
	i = 0;
	while (i < y)
		if (!(stru->map[i++] = malloc(sizeof(char) * (x_max + 1))))
			return (-1);
	return (x_max);
}

int		alloc_matrix(char *map, t_stru *stru)
{
	int x;
	int y;

	if ((y = alloc_y(map, stru)) == -1)
		return (1);
	if ((x = alloc_x(map, stru, y)) == -1)
		return (1);
	end(x, y, stru);
	return (0);
}
