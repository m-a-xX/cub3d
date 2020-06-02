/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:00:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/02 03:32:03 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calcul_height_column(t_stru *stru)
{
	if (stru->side == 0)
		stru->perp_wall_dist = (stru->map_x - stru->pos_x +
								(1 - stru->stepX) / 2) / stru->raydir_x;
	else
		stru->perp_wall_dist = (stru->map_y - stru->pos_y +
								(1 - stru->stepY) / 2) / stru->raydir_y;
	stru->line_height = (int)(stru->screen_height / stru->perp_wall_dist);
	stru->draw_start = -stru->line_height / 2 + stru->screen_height / 2;
	if (stru->draw_start < 0)
		stru->draw_start = 0;
	stru->draw_end = stru->line_height / 2 + stru->screen_height / 2;
	if (stru->draw_end >= stru->screen_height)
		stru->draw_end = stru->screen_height - 1;
}

void	loop(t_stru *stru, t_texture_column *col, int x)
{
	int					i;

	while (col->y < stru->draw_end)
	{
		col->pixel_index = (x + (col->y * stru->screen_width)) * 4;
		col->tex_y = (int)col->tex_pos;
		col->tex_pos += col->step;
		i = -1;
		while (++i < 4)
			col->color[i] = stru->img[col->tex_num].pixels[col->tex_x * 4 +
			4 * stru->img[col->tex_num].width * col->tex_y + i];
		i = -1;
		while (++i < 4)
			stru->pixels[col->pixel_index + i] = col->color[i];
		col->y++;
	}
}

void	draw_column(t_stru *stru, int x)
{
	t_texture_column	*col;

	if (!(col = malloc(sizeof(t_texture_column))))
		return ;
	col->wall_x = (stru->side == 0) ? stru->map_y + stru->perp_wall_dist *
		stru->raydir_y : stru->map_x + stru->perp_wall_dist * stru->raydir_x;
	col->wall_x -= floor((col->wall_x));
	col->tex_num = (stru->side == 0) ? 1 : 0;
	if (stru->hit == 2)
		col->tex_num = 4;
	else if (stru->side == 1)
		col->tex_num = (stru->raydir_y > 0) ? 1 : 0; 
	else
		col->tex_num = (stru->raydir_x > 0) ? 2 : 3;
	col->tex_x = (int)(col->wall_x * (double)(stru->img[col->tex_num].width));
	if ((stru->side == 0 && stru->raydir_x > 0) || (stru->side == 1 &&
		stru->raydir_y < 0))
		col->tex_x = stru->img[col->tex_num].width - col->tex_x - 1;
	col->step = 1.0 * stru->img[col->tex_num].height / stru->line_height;
	col->tex_pos =	(stru->draw_start - stru->screen_height / 2 +
				stru->line_height / 2) * col->step;
	col->y = stru->draw_start;
	loop(stru, col, x);

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
		calcul_height_column(stru);
		draw_column(stru, x);
		s = stru->side;
		print_ray(stru);
		x++;
	}
}
