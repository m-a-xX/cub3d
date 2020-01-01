/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:36:11 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/01 01:09:44 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_path(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	return (ft_substr(line, i, ft_strlen(line) - i));
}

void	get_rgb(char *line, int i, t_stru *stru, int sol)
{
	i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (sol)
	{
		stru->r_sol = ft_atoi(line + i);
		while (line[i] && (ft_isdigit(line[i])))
			i++;
		i++;
		stru->g_sol = ft_atoi(line + i);
		while (line[i] && (ft_isdigit(line[i])))
			i++;
		i++;
		stru->b_sol = ft_atoi(line + i);
		return ;
	}
	stru->r_plaf = ft_atoi(line + i);
	while (line[i] && (ft_isdigit(line[i])))
		i++;
	i++;
	stru->g_plaf = ft_atoi(line + i);
	while (line[i] && (ft_isdigit(line[i])))
		i++;
	i++;
	stru->b_plaf = ft_atoi(line + i);
}

int		check_errors(t_stru *stru)
{
	if (stru->r_plaf > 255 || stru->r_plaf < 0)
		return (1);
	if (stru->g_plaf > 255 || stru->g_plaf < 0)
		return (1);
	if (stru->b_plaf > 255 || stru->b_plaf < 0)
		return (1);
	if (stru->r_sol > 255 || stru->r_sol < 0)
		return (1);
	if (stru->g_sol > 255 || stru->g_sol < 0)
		return (1);
	if (stru->b_sol > 255 || stru->b_sol < 0)
		return (1);
	if (!stru->map)
		return (1);
	if (!stru->res_x || !stru->res_x)
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
