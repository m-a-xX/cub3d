/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:28:21 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/09 03:51:03 by mavileo          ###   ########.fr       */
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
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, stru->screen_width, stru->screen_height);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp),
	&(stru->sizeline), &(stru->endian));
	return (0);
}
