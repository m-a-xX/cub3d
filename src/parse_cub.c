/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:09:19 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/12 21:23:16 by mavileo          ###   ########.fr       */
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
		stru->map = NULL;
	if (!map || !*map)
		return (1);
	printf("%s\n", map);
	while (*map == '\n')
		map++;
	if ((i = alloc_matrix(map, stru)))
		return (1);
	printf("|%s\n", map);
	fill_map(stru, map, i);
	return (0);
}

int		begin_pos(t_stru *stru)
{
	if (stru->begin_pos == 'N')
	{
		stru->orient.x = 0;
		stru->orient.y = -8;
		stru->angle = 270;
	}
	else if (stru->begin_pos == 'S')
	{
		stru->orient.x = 0;
		stru->orient.y = 8;
		stru->angle = 90;
	}
	else if (stru->begin_pos == 'E')
	{
		stru->orient.x = 8;
		stru->orient.y = 0;
		stru->angle = 0;
	}
	else if (stru->begin_pos == 'W')
	{
		stru->orient.x = -8;
		stru->orient.y = 0;
		stru->angle = 180;
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
	stru->inter_rays = FOV / stru->res.x;
	begin_pos(stru);
	return (0);
}
