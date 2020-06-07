/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:28:21 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/07 01:57:33 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		exit_hook(t_stru *stru)
{
	free_struct(stru, 1);
	stru = NULL;
	exit(0);
}

int		init_mlx(t_stru *stru)
{
	stru->mlx_ptr = mlx_init();
	if (stru->save == 0)
		stru->win_ptr = mlx_new_window(stru->mlx_ptr, stru->screen_width,
		stru->screen_height, "cub3d");
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, stru->screen_width,
					stru->screen_height);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp),
	&(stru->sizeline), &(stru->endian));
	return (0);
}

int		key_hook(int keyhook, t_stru *stru)
{
	if (keyhook == ESC)
		exit_hook(stru);
	vertical_move(keyhook, stru);
	horizontal_move(keyhook, stru);
	rotation_left(keyhook, stru);
	rotation_right(keyhook, stru);
	mlx_clear_window(stru->mlx_ptr, stru->win_ptr);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);
}

void	destroy_ptrs(t_stru *stru)
{
	if (stru->img_ptr)
		mlx_destroy_image(stru->mlx_ptr, stru->img_ptr);
	if (stru->img[0].img_ptr)
		mlx_destroy_image(stru->mlx_ptr, stru->img[0].img_ptr);
	if (stru->img[1].img_ptr)
		mlx_destroy_image(stru->mlx_ptr, stru->img[1].img_ptr);
	if (stru->img[2].img_ptr)
		mlx_destroy_image(stru->mlx_ptr, stru->img[2].img_ptr);
	if (stru->img[3].img_ptr)
		mlx_destroy_image(stru->mlx_ptr, stru->img[3].img_ptr);
	if (stru->img[4].img_ptr)
		mlx_destroy_image(stru->mlx_ptr, stru->img[4].img_ptr);
	if (stru->win_ptr)
		mlx_destroy_window(stru->mlx_ptr, stru->win_ptr);
}
