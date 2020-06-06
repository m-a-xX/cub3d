/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 00:59:17 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/07 00:25:23 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	delta_dist(t_stru *stru)
{
	if (stru->raydir_y == 0)
		stru->delta_dist_x = 0;
	else
	{
		if (stru->raydir_x == 0)
			stru->delta_dist_x = 1;
		else
			stru->delta_dist_x = fabs(1 / stru->raydir_x);
	}
	if (stru->raydir_x == 0)
		stru->delta_dist_y = 0;
	else
	{
		if (stru->raydir_y == 0)
			stru->delta_dist_y = 1;
		else
			stru->delta_dist_y = fabs(1 / stru->raydir_y);
	}
}

void	dda_init(t_stru *stru)
{
	delta_dist(stru);
	if (stru->raydir_x < 0)
		stru->side_dist_x = (stru->pos_x - stru->map_x) * stru->delta_dist_x;
	else
	{
		stru->step_x = 1;
		stru->side_dist_x = (stru->map_x + 1.0 - stru->pos_x) *
							stru->delta_dist_x;
	}
	if (stru->raydir_y < 0)
	{
		stru->step_y = -1;
		stru->side_dist_y = (stru->pos_y - stru->map_y) * stru->delta_dist_y;
	}
	else
	{
		stru->step_y = 1;
		stru->side_dist_y = (stru->map_y + 1.0 - stru->pos_y) *
							stru->delta_dist_y;
	}
}

void	dda(t_stru *stru)
{
	dda_init(stru);
	while (stru->hit == 0)
	{
		if (stru->side_dist_x < stru->side_dist_y)
		{
			stru->side_dist_x += stru->delta_dist_x;
			stru->map_x += stru->step_x;
			stru->side = 0;
		}
		else
		{
			stru->side_dist_y += stru->delta_dist_y;
			stru->map_y += stru->step_y;
			stru->side = 1;
		}
		if (stru->map[stru->map_y][stru->map_x] == '1')
			stru->hit = 1;
		if (stru->map[stru->map_y][stru->map_x] == '2')
			stru->hit = 2;
	}
}
