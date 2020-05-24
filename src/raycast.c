/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:00:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/25 01:17:12 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calcul__height_column(t_stru *stru)
{
	if (stru->side == 0)
		stru->perp_wall_dist = (stru->map_x - stru->pos_x +
								(1 - stru->stepX) / 2) / stru->raydir_x;
	else
		stru->perp_wall_dist = (stru->map_y - stru->pos_y +
								(1 - stru->stepY) / 2) / stru->raydir_y;
	stru->line_height = (int)(stru->screen_height / stru->perp_wall_dist);
	stru->drawStart = -stru->line_height / 2 + stru->screen_height / 2;
	if (stru->drawStart < 0)
		stru->drawStart = 0;
	stru->drawEnd = stru->line_height / 2 + stru->screen_height / 2;
	if (stru->drawEnd >= stru->screen_height)
		stru->drawEnd = stru->screen_height - 1;
}

void	draw_column(t_stru *stru, int x)
{
	t_color color;

	if (stru->map[stru->map_y][stru->map_x] == '1')
		color = create_color(25, 65, 112);
	else if (stru->map[stru->map_y][stru->map_x] == '2')
		color = create_color(255, 0, 0);
	else if (stru->map[stru->map_y][stru->map_x] == '3')
		color = create_color(0, 0, 255);
	if (stru->side == 1)
	{
		color.r = color.r / 2;
		color.g = color.g / 2;
		color.b = color.b / 2;
	}
	while (stru->drawStart <= stru->drawEnd)
		put_pixel(stru, color, x, stru->drawStart++);
}

void	top_floor(t_stru *stru)
{
	int		x;
	int		y;

	y = 0;
	while (y <= stru->screen_height)
	{
		x = 0;
		while (x <= stru->screen_width)
		{
			if (y <= stru->screen_height / 2)
				put_pixel(stru, stru->rgb_top, x, y);
			else
				put_pixel(stru, stru->rgb_floor, x, y);
			x++;
		}
		y++;
	}
	print_pos(stru);
}

void	raycast(t_stru *stru)
{
	int x;
	int old_s;
	int s;

	x = 0;
	old_s = 0;
	s = 0;
	top_floor(stru);
	while (x < stru->screen_width)
	{
		old_s = s;
		stru->camera_x = (2 * x / (double)(stru->screen_width)) - 1;
		stru->raydir_x = stru->dir_x + stru->plane_x * stru->camera_x;
		stru->raydir_y = stru->dir_y + stru->plane_y * stru->camera_x;
		stru->map_x = (int)(stru->pos_x);
		stru->map_y = (int)(stru->pos_y);
		stru->hit = 0;
		stru->stepX = -1;
		dda(stru);
		calcul__height_column(stru);
		draw_column(stru, x);
		s = stru->side;
		print_ray(stru);
		x++;
	}
}
