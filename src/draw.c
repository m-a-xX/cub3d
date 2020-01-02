/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 20:42:46 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/01 21:55:43 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		convert_colors(int r, int b, int g)
{
	unsigned char converter[4];

	converter[0] = b;
	converter[1] = g;
	converter[2] = r;
	converter[3] = 0;
	return(*((int *)converter));
}

void	put_pixel(t_stru *stru, t_color color, int x, int y)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= stru->res_x || y < 0 || y >= stru->res_y)
		return ;
	pixel_index = x + (y * stru->res_x);
	rel_pixel_index = pixel_index * 4;
	stru->pixels[rel_pixel_index + RED_VALUE] = color.r;
	stru->pixels[rel_pixel_index + GREEN_VALUE] = color.g;
	stru->pixels[rel_pixel_index + BLUE_VALUE] = color.b;
}

void	draw_rectangle(t_stru *stru, t_rect rect, t_color color)
{
	int x_save;

	x_save = rect.x;
	while (rect.y < rect.vect_y)
	{
		rect.x = x_save;
		while (rect.x < rect.vect_x)
		{
			put_pixel(stru, color, rect.x, rect.y);
			rect.x++;
		}
		rect.y++;
	}
}
