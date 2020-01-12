/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:42:46 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/12 01:10:51 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_pixel(t_stru *stru, t_color color, int x, int y)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= stru->res.x || y < 0 || y >= stru->res.y)
		return ;
	pixel_index = x + (y * stru->res.x);
	rel_pixel_index = pixel_index * 4;
	stru->pixels[rel_pixel_index + RED_VALUE] = color.r;
	stru->pixels[rel_pixel_index + GREEN_VALUE] = color.g;
	stru->pixels[rel_pixel_index + BLUE_VALUE] = color.b;
}

void	draw_line(t_stru *stru, t_vect pos1, t_vect pos2, t_color color)
{
	t_vect	d;
	t_vect	s;
	int		err;
	int		e2;

	d.x = abs(pos2.x - pos1.x);
	s.x = pos1.x < pos2.x ? 1 : -1;
	d.y = abs(pos2.y - pos1.y);
	s.y = pos1.y < pos2.y ? 1 : -1; 
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (!(pos1.x == pos2.x && pos1.y == pos2.y))
	{
		put_pixel(stru, color, pos1.x, pos1.y);
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			pos1.x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			pos1.y += s.y;
		}
	}
}

void	draw_rectangle(t_stru *stru, t_rect rect, t_color color)
{
	while (rect.dep.y <= rect.end.y)
	{
		draw_line(stru, rect.dep, create_vect(rect.end.x, rect.dep.y), color);
		rect.dep.y++;
	}
}

void	draw_circle(t_stru *stru, t_vect coord, t_color color, int radius)
{
	t_vect	actual;
	int		target_x;
	int		target_y;

	target_x = coord.x + radius;
	target_y = coord.y + radius;
	actual.x = coord.x - radius;
	while (actual.x < target_x)
	{
		actual.y = coord.y - radius;
		while (actual.y < target_y)
		{
			if (d_pythagore(coord, actual) <= radius)
				put_pixel(stru, color, actual.x, actual.y);
			actual.y++;
		}
		actual.x++;
	}
}

int		draw_vect(t_stru *stru, t_vect vect, int len)
{
	t_vect	vect2;
	t_vect	pos2;
	t_color color = create_color(255, 24, 255);

	vect2 = create_vect(0, 0);
	while (abs(vect2.x) < len && abs(vect2.y) < len)
		vect2 = add_vects(vect2, vect);
	pos2 = add_vects(stru->pixel_pos, vect2);
	draw_line(stru, stru->pixel_pos, pos2, color);
	return (0);
}
