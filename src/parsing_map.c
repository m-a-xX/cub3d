/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:58:55 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/05 05:44:13 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_map(t_stru *stru, char *map, int i, int x)
{
	int y;

	y = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			stru->map[y][x] = 0;
			y++;
			x = 0;
		}
		else
		{
			if (map[i] == 'N' || map[i] == 'E' || map[i] == 'W' ||
			map[i] == 'S')
			{
				stru->pos_x = (double)x;
				stru->pos_y = (double)y;
				stru->begin_dir = map[i];
			}
			stru->map[y][x++] = map[i];
		}
		i++;
	}
}

int		check_dep(t_stru *stru)
{
	int		i;
	int		j;
	char	c;
	int		dep;

	dep = 1;
	j = 0;
	while (stru->map[j])
	{
		i = 0;
		while (stru->map[j][i])
		{
			c = stru->map[j][i];
			if (c == 'S' || c == 'N' || c == 'E' || c == 'W')
				dep = 0;
			i++;
		}
		j++;
	}
	return (dep);
}

int		check_spaces(t_stru *stru)
{
	int x;
	int y;

	y = -1;
	while (stru->map[++y])
	{
		x = -1;
		while (stru->map[y][++x])
		{
			if (stru->map[y][x] == ' ' && x > 0 && stru->map[y][x - 1]
				!= ' ' && stru->map[y][x - 1] != '1')
				return (1);
			if (stru->map[y][x] == ' ' && x < stru->map_width - 1 &&
				stru->map[y][x + 1] != ' ' && stru->map[y][x + 1] != '1')
				return (1);
			if (stru->map[y][x] == ' ' && y < stru->map_height - 1 &&
				stru->map[y + 1][x] != ' ' && stru->map[y + 1][x] != '1')
				return (1);
			if ((stru->map[y][x] == ' ' && y > 0 && stru->map[y - 1][x] != ' '
				&& stru->map[y - 1][x] != '1') || (stru->map[y][x + 1] == 0 &&
				stru->map[y][x] != '1'))
				return (1);
		}
	}
	return (0);
}

void	spaces_to_wall(t_stru *stru)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (stru->map[y])
	{
		x = 0;
		while (stru->map[y][x])
		{
			if (stru->map[y][x] == ' ')
				stru->map[y][x] = '1';
			x++;
		}
		while (x < stru->map_width - 1)
			stru->map[y][x++] = '1';
		stru->map[y][x] = 0;
		y++;
	}
}

int		check_map(t_stru *stru)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (check_spaces(stru))
		return (1);
	spaces_to_wall(stru);
	while (stru->map[0][i])
		if (stru->map[0][i++] != '1')
			return (1);
	i--;
	while (stru->map[j])
		if (stru->map[j][0] != '1' || stru->map[j++][i] != '1')
			return (1);
	j--;
	while (stru->map[j][i])
		if (stru->map[j][i++] != '1')
			return (1);
	return (check_dep(stru));
}
