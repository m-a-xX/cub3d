/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:08:09 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/25 00:37:13 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clear(t_stru *stru)
{
	int x;
	int y;

	x = 0;
	while (x < stru->screen_width)
	{
		y = 0;
		while (y < stru->screen_height)
			put_pixel(stru, create_color(0, 0, 0), x, y++);
		x++;
	}
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
}

void	put_pixel(t_stru *stru, t_color color, int x, int y)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= stru->screen_width || y < 0 || y >= stru->screen_height)
		return ;
	pixel_index = x + (y * stru->screen_width);
	rel_pixel_index = pixel_index * 4;
	stru->pixels[rel_pixel_index + RED_VALUE] = color.r;
	stru->pixels[rel_pixel_index + GREEN_VALUE] = color.g;
	stru->pixels[rel_pixel_index + BLUE_VALUE] = color.b;
}

double	d_pythagore(int a_x, int b_x, int a_y, int b_y)
{
	return (sqrt(pow((double)(b_x - a_x), 2) + pow((double)(b_y - a_y), 2)));
}

void	draw_circle(t_stru *stru, int coord_x, int coord_y, int radius)
{
	int		actual_x;
	int		actual_y;
	int		target_x;
	int		target_y;

	target_x = coord_x + radius;
	target_y = coord_y + radius;
	actual_x = coord_x - radius;
	while (actual_x < target_x)
	{
		actual_y = coord_y - radius;
		while (actual_y < target_y)
		{
			if (d_pythagore(coord_x, actual_x, coord_y, actual_y) <= radius)
				put_pixel(stru, create_color(255, 255, 255), actual_x,
				actual_y);
			actual_y++;
		}
		actual_x++;
	}
}

void	draw_line(t_stru *stru, int pos1_x, int pos1_y, int pos2_x, int pos2_y, t_color color)
{
	int		d_x;
	int		d_y;
	int		s_x;
	int		s_y;
	int		err;
	int		e2;

	d_x = abs(pos2_x - pos1_x);
	s_x = pos1_x < pos2_x ? 1 : -1;
	d_y = abs(pos2_y - pos1_y);
	s_y = pos1_y < pos2_y ? 1 : -1; 
	err = (d_x > d_y ? d_x : -d_y) / 2;
	while (!(pos1_x == pos2_x && pos1_y == pos2_y))
	{
		put_pixel(stru, color, pos1_x, pos1_y);
		e2 = err;
		if (e2 > -d_x)
		{
			err -= d_y;
			pos1_x += s_x;
		}
		if (e2 < d_y)
		{
			err += d_x;
			pos1_y += s_y;
		}
	}
}
