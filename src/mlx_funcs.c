/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:28:21 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/05 05:38:45 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		exit_hook(t_stru *stru)
{
	free(stru);
	stru = NULL;
	exit(0);
}

int		init_mlx(t_stru *stru)
{
	stru->mlx_ptr = mlx_init();
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
	clear(stru);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);
}
