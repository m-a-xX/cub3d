/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:53:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/12 00:54:12 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		expose_hook(t_stru *stru)
{
	t_vect to_print;
	t_color color = create_color(255, 24, 255);
	mlx_clear_window(stru->mlx_ptr, stru->win_ptr);
	to_print = adapt_to_res(stru->pixel_pos, stru->len_sprite);
	draw_circle(stru, create_vect(stru->pixel_pos.x, stru->pixel_pos.y),
	color, 5);
	draw_vect(stru, stru->orient, 50);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);
}

int		orient(t_stru *stru, int right)
{
	if (right)
		stru->angle += 10;
	else
		stru->angle -= 10;
	if (stru->angle > 360)
		stru->angle = stru->angle - 360;
	else if (stru->angle < 0)
		stru->angle = 360 - abs((int)stru->angle);
	stru->orient.x = cos(deg_to_rad(stru->angle)) * 8;
	stru->orient.y = sin(deg_to_rad(stru->angle)) * 8;
	return (0);
}

int		actualise_pos(t_stru *stru)
{
	stru->pixel_pos = add_vects(stru->pixel_pos, stru->move);
	if (stru->pixel_pos.x < stru->len_sprite.x)
		stru->pixel_pos.x -= stru->move.x;
	if (stru->pixel_pos.y < stru->len_sprite.y)
		stru->pixel_pos.y -= stru->move.y;
	if (stru->pixel_pos.x > stru->res.x - stru->len_sprite.x)
		stru->pixel_pos.x -= stru->move.x;
	if (stru->pixel_pos.y > stru->res.y - stru->len_sprite.y)
		stru->pixel_pos.y -= stru->move.y;
	return (0);
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
/* 
int		draw_pov(t_stru *stru)
{
	
	
	return (0);
}
 */

int		key_hook(int keyhook, t_stru *stru)
{
	if (keyhook == 13)
	{
		stru->move.y = stru->orient.y;
		stru->move.x = stru->orient.x;
	}
	else if (keyhook == 1)
	{
		stru->move.y = -stru->orient.y;
		stru->move.x = -stru->orient.x;
	}
 	else if (keyhook == 0)
	{
		stru->move.x = stru->orient.y;
		stru->move.y = -stru->orient.x;
	}
	else if (keyhook == 2)
	{
		stru->move.x = -stru->orient.y;
		stru->move.y = stru->orient.x;
	}
	else if (keyhook == 123)
	{
		stru->move = create_vect(0, 0);
		orient(stru, 0);
	}
	else if (keyhook == 124)
	{
		stru->move = create_vect(0, 0);
		orient(stru, 1);
	}
	else
		return (0);
	actualise_pos(stru);
	expose_hook(stru);
	return (0);
}

int		cub3d(t_stru *stru)
{
	t_color color;

	init_mlx(stru);
	color = create_color(255, 24, 255);
	stru->pixel_pos = mult_vects(stru->pos, stru->len_sprite);
	draw_circle(stru, stru->pixel_pos, color, 5);
	draw_vect(stru, stru->orient, 50);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_loop_hook(stru->mlx_ptr, loop_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}
