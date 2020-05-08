/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/05/08 17:33:26 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int             cub3d(t_stru *stru)
{
	stru->posX = 22;
	stru->posY = 11;

	stru->screenHeight = 400;
	stru->screenWidth = 600;

	stru->mapHeight = 24;
	stru->mapWidth = 24;

	stru->dirX = -1;
	stru->dirY = 0;
	stru->moveSpeed = 0.1;
	stru->rotSpeed = 0.1;
	

	init_mlx(stru);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_hook(stru->win_ptr, 2, 1L<<0, key_hook, stru);
	mlx_hook(stru->win_ptr, 17, 0, exit_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}

int main()
{
	t_stru *stru = malloc(sizeof(t_stru));
	cub3d(stru);
}