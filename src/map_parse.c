/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:58:55 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/04 02:59:30 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		alloc_matrix(char *map, t_stru *stru)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	if (!(stru->map = calloc(1, 1)))
		return (1);
	while (map[i])
	{
		if (map[i] == '\n')
			y++;
		i++;
	}
	if (!(stru->map = malloc(sizeof(char *) * (y + 1))))
		return (1);
	while (map[x] && map[x] != '\n')
		x++;
	i = 0;
	while (i < y)
		if (!(stru->map[i++] = malloc(sizeof(char) * (x + 1))))
			return (1);
	stru->map[i] = NULL;
	return (0);
}

void	departure_angle(t_stru *stru, char *map, int i)
{
	if (map[i] == 'N')
		stru->angle = 90;
	if (map[i] == 'S')
		stru->angle = 270;
	if (map[i] == 'E')
		stru->angle = 0;
	if (map[i] == 'W')
		stru->angle = 180;
}

void	fill_map(t_stru *stru, char *map, int i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			stru->map[y][x] = 0;
			y++;
			x = 0;
		}
		else if (map[i] != ' ')
		{
			if (map[i] == 'N' || map[i] == 'E' || map[i] == 'W' || map[i] == 'S')
			{
				stru->pos.x = x;
				stru->pos.y = y;
				departure_angle(stru, map, i);
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

int		check_map(t_stru *stru)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
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
