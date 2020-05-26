/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:00:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/27 00:00:03 by mavileo          ###   ########.fr       */
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
	stru->draw_start = -stru->line_height / 2 + stru->screen_height / 2;
	if (stru->draw_start < 0)
		stru->draw_start = 0;
	stru->draw_end = stru->line_height / 2 + stru->screen_height / 2;
	if (stru->draw_end >= stru->screen_height)
		stru->draw_end = stru->screen_height - 1;
}

void	draw_column(t_stru *stru, int x)
{
	double	wall_x;
	int		texWidth = 255;
	int		texHeight = 255;
	int		texX;
	int pixel_index;
	int rel_pixel_index;

	if (stru->side == 0)
		wall_x = stru->map_y + stru->perp_wall_dist * stru->raydir_y;
	else
		wall_x = stru->map_x + stru->perp_wall_dist * stru->raydir_x;
	wall_x -= floor((wall_x));
	texX = (int)(wall_x * (double)(texWidth));
	if (stru->side == 0 && stru->raydir_x > 0)
		texX = texWidth - texX - 1;
    if (stru->side == 1 && stru->raydir_y < 0)
		texX = texWidth - texX - 1;
	double step = 1.0 * texHeight / stru->line_height;
	// Starting texture coordinate
	double texPos = (stru->draw_start - stru->screen_height / 2 + stru->line_height / 2) * step;
	//printf("%d\n%d\n%d\n\n", x, stru->draw_start, x+ stru->draw_start * stru->screen_width);
	//printf("%d\n", stru->screen_width * ((int)texPos & (texHeight - 1)) * 4 + texX);
	//printf("okkkk\n");
	for (int y = stru->draw_start; y < stru->draw_end; y++)
	{
		pixel_index = x + (y * stru->screen_width);
		rel_pixel_index = pixel_index * 4;
		int texY = (int)texPos & (texHeight - 1);
		texPos += step;
		int color = stru->img[0].pixels[texHeight * texY + texX];
		//stru->pixels[pixel_index] = color;
		stru->pixels[rel_pixel_index + 0] = (color >> 24) & 0xFF;
		stru->pixels[rel_pixel_index + 1] = (color >> 16) & 0xFF;
		stru->pixels[rel_pixel_index + 2] = (color >> 8) & 0xFF;
		stru->pixels[rel_pixel_index + 3] = color & 0xFF;
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		//if (side == 1) color = (color >> 1) & 8355711;
	}
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
