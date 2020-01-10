/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:53:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/10 11:47:34 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		expose_hook(t_stru *stru)
{
	t_vect to_print;
	t_color color = create_color(255, 24, 255);
	mlx_clear_window(stru->mlx_ptr, stru->win_ptr);
	to_print = adapt_to_res(stru->pixel_pos, stru->len_sprite);
	draw_circle(stru, create_vect(stru->pixel_pos.x, stru->pixel_pos.y), color, 15);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);
}

int		key_hook(int keyhook, t_stru *stru)
{
	if (keyhook == 13)
		stru->pixel_pos.y -= 16;
	if (keyhook == 1)
		stru->pixel_pos.y += 16;
	if (keyhook == 0)
		stru->pixel_pos.x -= 16;
	if (keyhook == 2)
		stru->pixel_pos.x += 16;
	//if (keyhook == 123)
		//stru->angle += 1;
	//if (keyhook == 124)
		//stru->angle -= 1;
	expose_hook(stru);
	return (0);
}

int		exit_hook(t_stru *stru)
{
	free(stru);
	stru = NULL;
	exit(0);
}

int		loop_hook(t_stru *stru)
{
	mlx_hook(stru->win_ptr, 2, 0, key_hook, stru);
	mlx_hook(stru->win_ptr, 17, 0, exit_hook, stru);
	return (0);
}

int		cub3d(t_stru *stru)
{
	t_vect to_print;
	t_color color;

	stru->mlx_ptr = mlx_init();
	stru->win_ptr = mlx_new_window(stru->mlx_ptr, stru->res.x,
	stru->res.y, "cub3d");
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, stru->res.x, stru->res.y);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp), &(stru->sizeline), &(stru->endian));
	calcul_dist_screen(stru);
	calcul_sprite_len(stru);
	color = create_color(255, 24, 255);
	stru->pixel_pos = mult_vect(stru->pos, stru->len_sprite);
	draw_circle(stru, stru->pixel_pos, color, 15);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_loop_hook(stru->mlx_ptr, loop_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}
