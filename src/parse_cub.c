/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:09:19 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/19 08:15:43 by mavileo          ###   ########.fr       */
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
	if (!(stru->map = malloc(sizeof(char *) * y)))
		return (1);
	while (map[x] && map[x] != '\n')
		x++;
	i = 0;
	while (i < y)
		if (!(stru->map[i++] = malloc(sizeof(char) * (x + 1))))
			return (1);
	return (0);
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
				stru->dep_x = x;
				stru->dep_y = y;
				stru->dep_pos = map[i];
			}
			stru->map[y][x++] = map[i];
		}
		i++;
	}
}

int		tab_to_matrix(t_stru *stru, char *map)
{
	int i;

	if (!map || !*map)
		stru->map = NULL;
	if (!map || !*map)
		return (1);
	if ((i = alloc_matrix(map, stru)))
		return (1);
	fill_map(stru, map, i);
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
	if ((tab_to_matrix(stru, map)))
		return (1);
	if (check_errors(stru))
		ft_putstr_fd("Error\n", 1);
	if (check_errors(stru))
		return (1);
	return (0);
}
