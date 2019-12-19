/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:09:19 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/19 03:00:10 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	res(int i, t_stru *stru, char *line)
{
	stru->res_x = ft_atoi(line + i + 1);
	while (line[i] && (line[i] == 'R' || line[i] == ' '))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	stru->res_y = ft_atoi(line + i);
}

int		analyse_line(char *line, t_stru *stru, int i)
{
	static int	count = 0;

	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && count++ >= 0)
		stru->path_nord = get_path(line, i + 2);
	if (line[i] == 'S' && line[i + 1] == 'O' && count++ >= 0)
		stru->path_sud = get_path(line, i + 2);
	if (line[i] == 'W' && line[i + 1] == 'E' && count++ >= 0)
		stru->path_ouest = get_path(line, i + 2);
	if (line[i] == 'E' && line[i + 1] == 'A' && count++ >= 0)
		stru->path_est = get_path(line, i + 2);
	if (line[i] == 'S' && count++ >= 0)
		stru->path_sprite = get_path(line, i + 1);
	if (line[i] == 'F' && count++ >= 0)
		get_rgb(line, i, stru, 1);
	if (line[i] == 'C' && count++ >= 0)
		get_rgb(line, i, stru, 0);
	if (line[i] == 'R' && count++ >= 0)
		res(i, stru, line);
	return (count);
}

void	alloc_matrix(char *map, t_stru *stru)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	if (!(stru->map = calloc(1, 1)))
		return ;
	while (map[i])
	{
		if (map[i] == '\n')
			y++;
		i++;
	}
	if (!(stru->map = malloc(sizeof(char *) * y)))
		return ;
	while (map[x] && map[x] != '\n')
		x++;
	i = 0;
	while (i < y)
		if (!(stru->map[i++] = malloc(sizeof(char) * (x + 1))))
			return ;
}

void	tab_to_matrix(t_stru *stru, char *map)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	if (!map || !*map)
	{
		stru->map = NULL;
		return ;
	}
	alloc_matrix(map, stru);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			stru->map[y][x] = 0;
			y++;
			x = 0;
			i++;
		}
		else
			stru->map[y][x++] = map[i++];
	}
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
	tab_to_matrix(stru, map);
	if (check_errors(stru))
		ft_putstr_fd("Error\n", 1);
	if (check_errors(stru))
		return (1);
	return (0);
}
