/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:36:11 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/04 03:01:15 by mavileo          ###   ########.fr       */
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
	if (stru->rgb_sol.r > 255 || stru->rgb_sol.r < 0)
		return (1);
	if (stru->rgb_sol.g > 255 || stru->rgb_sol.g < 0)
		return (1);
	if (stru->rgb_sol.b > 255 || stru->rgb_sol.b < 0)
		return (1);
	if (stru->rgb_plafond.r > 255 || stru->rgb_plafond.r < 0)
		return (1);
	if (stru->rgb_plafond.g > 255 || stru->rgb_plafond.g < 0)
		return (1);
	if (stru->rgb_plafond.b > 255 || stru->rgb_plafond.b < 0)
		return (1);
	if (!stru->map)
		return (1);
	if (stru->res.x < 1 || stru->res.y < 1)
		return (1);
	if (!stru->path_nord)
		return (1);
	if (!stru->path_sud)
		return (1);
	if (!stru->path_est)
		return (1);
	if (!stru->path_ouest)
		return (1);
	return (0);
}

void	res(int i, t_stru *stru, char *line)
{
	stru->res.x = ft_atoi(line + i + 1);
	while (line[i] && (line[i] == 'R' || line[i] == ' '))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	stru->res.y = ft_atoi(line + i);
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
		stru->rgb_sol = get_rgb(line, i);
	if (line[i] == 'C' && count++ >= 0)
		stru->rgb_plafond = get_rgb(line, i);
	if (line[i] == 'R' && count++ >= 0)
		res(i, stru, line);
	return (count);
}
