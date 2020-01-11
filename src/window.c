/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:53:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/11 20:39:11 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		expose_hook(t_stru *stru)
{
	t_vect to_print;
	t_color color = create_color(255, 24, 255);
	mlx_clear_window(stru->mlx_ptr, stru->win_ptr);
	to_print = adapt_to_res(stru->pixel_pos, stru->len_sprite);
	draw_circle(stru, create_vect(stru->pixel_pos.x, stru->pixel_pos.y), color, 5);
	draw_vect(stru, stru->stock_dir, 50);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);
}

int		rotation(t_stru *stru, int right)
{
	float c;
	float s;

	if (right)
	{
		c = cos(M_PI/12);
		s = sin(M_PI/12);
	}
	else
	{
		c = cos(-M_PI/12);
		s = sin(-M_PI/12);
	}
	stru->direction.x = c * stru->direction.x - s * stru->direction.y;
	stru->direction.y = s * stru->direction.x + c * stru->direction.y;
	//stru->stock_dir = stru->direction;
	return (0);
}

int		actualise_pos(t_stru *stru)
{
	if (stru->direction.x || stru->direction.y)
		stru->stock_dir = stru->direction;
	stru->pixel_pos = add_vects(stru->pixel_pos, stru->direction);
	if (stru->pixel_pos.x < stru->len_sprite.x)
		stru->pixel_pos.x -= stru->direction.x;
	if (stru->pixel_pos.y < stru->len_sprite.y)
		stru->pixel_pos.y -= stru->direction.y;
	if (stru->pixel_pos.x > stru->res.x - stru->len_sprite.x)
		stru->pixel_pos.x -= stru->direction.x;
	if (stru->pixel_pos.y > stru->res.y - stru->len_sprite.y)
		stru->pixel_pos.y -= stru->direction.y;
	return (0);
}

int		draw_vect(t_stru *stru, t_vect vect, int len)
{
	t_vect	vect2;
	t_vect	pos2;
	t_color color = create_color(255, 24, 255);

	vect2 = create_vect(0, 0);
	//ft_putnbr_fd(vect2.x, 1);
	//ft_putnbr_fd(vect2.y, 1);
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
		stru->direction.y = -8;
		stru->direction.x = 0;
	}
	else if (keyhook == 1)
	{
		stru->direction.y = +8;
		stru->direction.x = 0;
	}
	else if (keyhook == 0)
	{
		stru->direction.x = -8;
		stru->direction.y = 0;
	}
	else if (keyhook == 2)
	{
		stru->direction.x = +8;
		stru->direction.y = 0;
	}
	else if (keyhook == 123) //gauche
		rotation(stru, 0);
	else if (keyhook == 124)
		rotation(stru, 1);
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
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_loop_hook(stru->mlx_ptr, loop_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}
