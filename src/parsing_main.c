/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:09:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/09 03:49:56 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		error_parsing(void)
{
	ft_putstr_fd("Error\nUn problème est survenu lors du parsing.\n\
Merci de vérifier la validité du ficher .cub", 1);
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
	fill_map(stru, map, i);
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
	if (stru->begin_dir == 'N')
	{
		stru->plane_x = -0.66;
		stru->plane_y = 0;
	}
	else if (stru->begin_dir == 'S')
	{
		stru->plane_x = 0.66;
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
		stru->plane_y = 0.66;
	}
	return (0);
}

int		parse_cub(int fd, t_stru *stru)
{
	char	*line;
	char	*map;
	int		count;
	int		i;

	i = 0;
	count = 0;
	map = NULL;
	while (count <= 8 && get_next_line(fd, &line) > 0)
	{
		count = analyse_line(line, stru, i);
		free(line);
	}
	if (count < 9)
		ft_putstr_fd("Error\n", 1);
	if (count < 9)
		return (1);
	while (get_next_line(fd, &line) > 0)
		map = strjoin_free_nl(map, line);
	if ((tab_to_matrix(stru, map)) || check_stru(stru) || check_map(stru))
		return (error_parsing());
	begin_dir(stru);
	begin_plane(stru);
	return (0);
}
