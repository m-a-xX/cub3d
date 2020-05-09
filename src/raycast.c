/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:00:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/09 03:53:09 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dda_init(t_stru *stru)
{
	stru->delta_dist_x = (stru->raydir_y == 0) ? 0 : ((stru->raydir_x == 0) ? 1 : fabs(1 / stru->raydir_x));
	stru->delta_dist_y = (stru->raydir_x == 0) ? 0 : ((stru->raydir_y == 0) ? 1 : fabs(1 / stru->raydir_y));

	if (stru->raydir_x < 0)
		stru->side_dist_x = (stru->pos_x - stru->map_x) * stru->delta_dist_x;
	else
	{
		stru->stepX = 1;
		stru->side_dist_x = (stru->map_x + 1.0 - stru->pos_x) * stru->delta_dist_x;
	}
	if (stru->raydir_y < 0)
	{
		stru->stepY = -1;
		stru->side_dist_y = (stru->pos_y - stru->map_y) * stru->delta_dist_y;
	}
	else
	{
		stru->stepY = 1;
		stru->side_dist_y = (stru->map_y + 1.0 - stru->pos_y) * stru->delta_dist_y;
	}
}

void	dda(t_stru *stru)
{
	while (stru->hit == 0)
	{
		if (stru->side_dist_x < stru->side_dist_y)
		{
			stru->side_dist_x += stru->delta_dist_x;
			stru->map_x += stru->stepX;
			stru->side = 0;
		}
		else
		{
			stru->side_dist_y += stru->delta_dist_y;
			stru->map_y += stru->stepY;
			stru->side = 1;
		}
		if (stru->map[stru->map_x][stru->map_y] > '0')
			stru->hit = 1;
	}
}

void	calcul__height_column(t_stru *stru)
{
	if (stru->side == 0)
		stru->perp_wall_dist = (stru->map_x - stru->pos_x + (1 - stru->stepX) / 2) / stru->raydir_x;
	else
		stru->perp_wall_dist = (stru->map_y - stru->pos_y + (1 - stru->stepY) / 2) / stru->raydir_y;
	stru->line_height = (int)(stru->screen_height / stru->perp_wall_dist);
	stru->drawStart = -stru->line_height / 2 + stru->screen_height / 2;
	if(stru->drawStart < 0)
		stru->drawStart = 0;
	stru->drawEnd = stru->line_height / 2 + stru->screen_height / 2;
	if(stru->drawEnd >= stru->screen_height)
		stru->drawEnd = stru->screen_height - 1;
}

void	draw_column(t_stru *stru, int x)
{
	t_color color;
	
	switch(stru->map[stru->map_x][stru->map_y])
	{
		case '1':	color = create_color(25, 65, 112);	break;
		case '2':	color = create_color(25, 0, 112);	break;
		case '3':	color = create_color(150, 54, 35);	 break;
		case '4':	color = create_color(2, 65, 200);	break;
		default: color = create_color(0, 65, 112); break;
	}
	if (stru->side == 1)
	{
		color.r = color.r / 2;
		color.g = color.g / 2;
		color.b = color.b / 2;
	}
	while (stru->drawStart <= stru->drawEnd)
		put_pixel(stru, color, x, stru->drawStart++);
}

void	raycast(t_stru *stru)
{
	int x;

	x = 0;
	stru->plane_x = 0;
	stru->plane_y = 0.66;
	int oldS = 0, S = 0;
	print_pos(stru);
	while (x < stru->screen_width)
	{
		oldS = S;
		stru->camera_x = (2 * x / (double)(stru->screen_width)) - 1;
		stru->raydir_x = stru->dir_x + stru->plane_x * stru->camera_x;
		stru->raydir_y = stru->dir_y + stru->plane_y * stru->camera_x;
		stru->map_x = (int)(stru->pos_x);
		stru->map_y = (int)(stru->pos_y);
		stru->hit = 0;
		stru->stepX = -1;
		dda_init(stru);
		dda(stru);
		calcul__height_column(stru);
		draw_column(stru, x);
		S = stru->side;
		//draw_line(stru, stru->pos_x*5, stru->pos_y*5, stru->pos_x*5 + go_to(stru->raydir_x, 20), stru->pos_y*5 + go_to(stru->raydir_y, 20), create_color(255,255,255));
		draw_line(stru, stru->pos_x*5, stru->pos_y*5, stru->pos_x*5 + (stru->raydir_x * 20), stru->pos_y*5 + (stru->raydir_y * 20), create_color(244,143,228));
		if (x == 200 || x == 400)
		{
			printf("x %d\nperp_wall_dist %f\nline_height %d\nraydir_x %f\nraydir_y %f\n\n", x, stru->perp_wall_dist, stru->line_height, stru->raydir_x, stru->raydir_y);
		}
		x++;
	}
}
