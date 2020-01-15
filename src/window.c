/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:53:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/15 13:41:28 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		draw_fov(t_stru *stru)
{
	double	i;
	int		x;
	int		y;

	i = 0.01;
	while (i < 30)
	{
		x = cos(deg_to_rad(i)) * stru->orient.x - sin(deg_to_rad(i)) * stru->orient.y;
		y = sin(deg_to_rad(i)) * stru->orient.x + cos(deg_to_rad(i)) * stru->orient.y;
		draw_vect(stru, create_vect(x, y), 50);
		x = cos(deg_to_rad(-i)) * stru->orient.x - sin(deg_to_rad(-i)) * stru->orient.y;
		y = sin(deg_to_rad(-i)) * stru->orient.x + cos(deg_to_rad(-i)) * stru->orient.y;
		draw_vect(stru, create_vect(x, y), 50);
		i += 0.01;
	}
	return (0);
}

int		expose_hook(t_stru *stru)
{
	t_color color = create_color(255, 24, 255);
	
	//mlx_clear_window(stru->mlx_ptr, stru->win_ptr);
	clear_window(stru);
	draw_circle(stru, create_vect(stru->pixel_pos.x, stru->pixel_pos.y),
	color, 5);
	draw_vect(stru, stru->orient, 50);
	draw_fov(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);
}

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
		rotation(stru, 0);
	}
	else if (keyhook == 124)
	{
		stru->move = create_vect(0, 0);
		rotation(stru, 1);
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
	begin_pos(stru);
	stru->orient.y = -100;
	color = create_color(255, 24, 255);
	stru->pixel_pos = mult_vects(stru->pos, stru->len_sprite);
	draw_circle(stru, stru->pixel_pos, color, 5);
	draw_vect(stru, stru->orient, 50);
	draw_fov(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_loop_hook(stru->mlx_ptr, loop_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}
