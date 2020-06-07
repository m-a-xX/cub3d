/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:36:11 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/07 09:58:57 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_path(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	return (ft_substr(line, i, ft_strlen(line) - i));
}

t_color	get_rgb(char *line, int i)
{
	t_color color;

	i++;
	while (line[i] && line[i] == ' ')
		i++;
	color.r = ft_atoi(line + i);
	while (line[i] && (ft_isdigit(line[i])))
		i++;
	i++;
	color.g = ft_atoi(line + i);
	while (line[i] && (ft_isdigit(line[i])))
		i++;
	i++;
	color.b = ft_atoi(line + i);
	return (color);
}

int		check_stru(t_stru *stru)
{
	if (stru->rgb_floor.r > 255 || stru->rgb_floor.r < 0)
		return (1);
	if (stru->rgb_floor.g > 255 || stru->rgb_floor.g < 0)
		return (1);
	if (stru->rgb_floor.b > 255 || stru->rgb_floor.b < 0)
		return (1);
	if (stru->rgb_top.r > 255 || stru->rgb_top.r < 0)
		return (1);
	if (stru->rgb_top.g > 255 || stru->rgb_top.g < 0)
		return (1);
	if (stru->rgb_top.b > 255 || stru->rgb_top.b < 0)
		return (1);
	if (!stru->map)
		return (1);
	if (stru->screen_width < 1 || stru->screen_height < 1)
		return (1);
	if (!stru->path_north)
		return (1);
	if (!stru->path_south)
		return (1);
	if (!stru->path_est)
		return (1);
	if (!stru->path_west)
		return (1);
	return (0);
}

void	res(int i, t_stru *stru, char *line)
{
	stru->screen_width = ft_atoi(line + i + 1);
	while (line[i] && (line[i] == 'R' || line[i] == ' '))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	stru->screen_height = ft_atoi(line + i);
	if (stru->screen_width > 1800)
		stru->screen_width = 1800;
	if (stru->screen_height > 900)
		stru->screen_height = 900;
}

int		analyse_line(char *line, t_stru *stru, int i)
{
	static int	count = 0;

	if (check_keys(line, i))
		return (error_parsing(6));
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O' && count++ >= 0)
		stru->path_north = get_path(line, i + 3);
	if (line[i] == 'S' && line[i + 1] == 'O' && count++ >= 0)
		stru->path_south = get_path(line, i + 3);
	if (line[i] == 'W' && line[i + 1] == 'E' && count++ >= 0)
		stru->path_west = get_path(line, i + 3);
	if (line[i] == 'E' && line[i + 1] == 'A' && count++ >= 0)
		stru->path_est = get_path(line, i + 3);
	if (line[i] == 'S' && line[i + 1] == ' ' && count++ >= 0)
		stru->path_sprite = get_path(line, i + 2);
	if (line[i] == 'F' && count++ >= 0)
		stru->rgb_floor = get_rgb(line, i);
	if (line[i] == 'C' && count++ >= 0)
		stru->rgb_top = get_rgb(line, i);
	if (line[i] == 'R' && count++ >= 0)
		res(i, stru, line);
	return (count);
}
