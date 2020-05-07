/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/05/07 04:39:51 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int             cub3d(t_stru *stru)
{
	stru->posX = 22;
	stru->posY = 12;

	stru->screenHeight = 400;
	stru->screenWidth = 600;

	stru->mapHeight = 24;
	stru->mapWidth = 24;

	stru->dirX = -1;
	stru->dirY = 0;

	stru->moveSpeed = 0.2;
	stru->rotSpeed = 0.2;
	init_mlx(stru);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_key_hook(stru->win_ptr, key_hook, stru);
	mlx_loop_hook(stru->mlx_ptr, loop_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}

int main()
{
	t_stru *stru = malloc(sizeof(t_stru));
	cub3d(stru);
}