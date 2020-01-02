/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:53:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/02 15:38:28 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		cub3d(t_stru *stru)
{
	stru->mlx_ptr = mlx_init();
	stru->win_ptr = mlx_new_window(stru->mlx_ptr, stru->res_x,
	stru->res_y, "cub3d");
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, stru->res_x, stru->res_y);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp), &(stru->sizeline), &(stru->endian));
	draw_rectangle(stru, create_rect(0, 0, stru->res_x, stru->res_y / 2),
	stru->rgb_sol);
	draw_rectangle(stru, create_rect(0, stru->res_y / 2, stru->res_x, stru->res_y),
	stru->rgb_plafond);
	draw_rectangle(stru, create_rect(10, 100, 390, 300),
	create_color(255,255,255));
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_loop(stru->mlx_ptr);
	return (0);
}