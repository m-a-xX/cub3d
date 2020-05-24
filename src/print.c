/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo@student.42.fr <mavileo@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:08:09 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/24 18:20:21 by mavileo@stu      ###   ########.fr       */
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
			put_pixel(stru, create_color(0,0,0), x, y++);
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

double	d_pythagore(int aX, int bX, int aY, int bY)
{
	return (sqrt(pow((double)(bX - aX), 2) + pow((double)(bY - aY), 2)));
}

void	draw_circle(t_stru *stru, int coordX, int coordY, t_color color, int radius)
{
	int		actualX;
	int		actualY;
	int		target_x;
	int		target_y;

	target_x = coordX + radius;
	target_y = coordY + radius;
	actualX = coordX - radius;
	while (actualX < target_x)
	{
		actualY = coordY - radius;
		while (actualY < target_y)
		{
			if (d_pythagore(coordX, actualX, coordY, actualY) <= radius)
				put_pixel(stru, color, actualX, actualY);
			actualY++;
		}
		actualX++;
	}
}

void	draw_line(t_stru *stru, int pos1X, int pos1Y, int pos2X, int pos2Y, t_color color)
{
	int		dX;
	int		dY;
	int		sX;
	int		sY;
	int		err;
	int		e2;

	dX = abs(pos2X - pos1X);
	sX = pos1X < pos2X ? 1 : -1;
	dY = abs(pos2Y - pos1Y);
	sY = pos1Y < pos2Y ? 1 : -1; 
	err = (dX > dY ? dX : -dY) / 2;
	while (!(pos1X == pos2X && pos1Y == pos2Y))
	{
		put_pixel(stru, color, pos1X, pos1Y);
		e2 = err;
		if (e2 > -dX)
		{
			err -= dY;
			pos1X += sX;
		}
		if (e2 < dY)
		{
			err += dX;
			pos1Y += sY;
		}
	}
}
