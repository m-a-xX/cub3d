/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:28:21 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/11 20:28:51 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int		init_mlx(t_stru *stru)
{
	stru->mlx_ptr = mlx_init();
	stru->win_ptr = mlx_new_window(stru->mlx_ptr, stru->res.x,
	stru->res.y, "cub3d");
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, stru->res.x, stru->res.y);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp),
	&(stru->sizeline), &(stru->endian));
	calcul_dist_screen(stru);
	calcul_sprite_len(stru);
	return (0);
}
