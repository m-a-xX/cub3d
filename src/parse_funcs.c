/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 07:36:11 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/19 02:55:13 by mavileo          ###   ########.fr       */
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
	stru->r_plafond = ft_atoi(line + i);
	while (line[i] && (ft_isdigit(line[i])))
		i++;
	i++;
	stru->g_plafond = ft_atoi(line + i);
	while (line[i] && (ft_isdigit(line[i])))
		i++;
	i++;
	stru->b_plafond = ft_atoi(line + i);
}

int		check_errors(t_stru *stru)
{
	if (stru->r_plafond > 255 || stru->r_plafond < 0)
		return (1);
	if (stru->g_plafond > 255 || stru->g_plafond < 0)
		return (1);
	if (stru->b_plafond > 255 || stru->b_plafond < 0)
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
