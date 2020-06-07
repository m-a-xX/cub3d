/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:09:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/07 10:16:13 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		error_parsing(int i)
{
	if (i == 2)
	{
		ft_putstr_fd("Error\nThere are at least one missing parameter in \
the .cub file\n", 1);
	}
	if (i == 3)
	{
		ft_putstr_fd("Error\nCan't create the map\n", 1);
	}
	if (i == 4)
	{
		ft_putstr_fd("Error\nOne or some parameters passed in the .cub file \
are invalids\n", 1);
	}
	if (i == 5)
		ft_putstr_fd("Error\nCheck the map passed in the .cub file\n", 1);
	if (i == 6)
	{
		ft_putstr_fd("Error\nCheck arguments passed in the .cub file\n", 1);
		return (-1);
	}
	return (1);
}

int		tab_to_matrix(t_stru *stru, char *map)
{
	int i;

	if (!map || !*map)
	{
		stru->map = NULL;
		return (1);
	}
	while (*map == '\n')
		map++;
	if ((i = alloc_matrix(map, stru)))
		return (1);
	fill_map(stru, map, i, 0);
	return (0);
}

int		begin_dir(t_stru *stru)
{
	if (stru->begin_dir == 'N')
	{
		stru->dir_x = 0;
		stru->dir_y = -1;
	}
	else if (stru->begin_dir == 'S')
	{
		stru->dir_x = 0;
		stru->dir_y = 1;
	}
	else if (stru->begin_dir == 'E')
	{
		stru->dir_x = 1;
		stru->dir_y = 0;
	}
	else if (stru->begin_dir == 'W')
	{
		stru->dir_x = -1;
		stru->dir_y = 0;
	}
	return (0);
}

int		begin_plane(t_stru *stru)
{
	begin_dir(stru);
	if (stru->begin_dir == 'N')
	{
		stru->plane_x = 0.66;
		stru->plane_y = 0;
	}
	else if (stru->begin_dir == 'S')
	{
		stru->plane_x = -0.66;
		stru->plane_y = 0;
	}
	else if (stru->begin_dir == 'E')
	{
		stru->plane_x = 0;
		stru->plane_y = 0.66;
	}
	else if (stru->begin_dir == 'W')
	{
		stru->plane_x = 0;
		stru->plane_y = -0.66;
	}
	return (0);
}

int		parse_cub(int fd, t_stru *stru)
{
	char	*line;
	int		count;
	int		i;
	int		ret;

	i = 0;
	count = 0;
	while (count <= 7 && get_next_line(fd, &line) > 0)
	{
		if (count == -1)
			return (1);
		count = analyse_line(line, stru, i);
		free(line);
	}
	if (count < 8)
		return (error_parsing(2));
	if ((ret = map_and_check(stru, fd)))
		return (ret);
	return (0);
}
