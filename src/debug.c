/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:19:55 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/25 00:51:48 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_pos(t_stru *stru)
{
	int x;
	int y;

	x = 5 * stru->map_width;
	y = 5 * stru->map_height;
	while (x >= 0)
	{
		y = 5 * 10;
		while (y >= 0)
		{
			if (stru->map[y / 5][x / 5] > '0')
				put_pixel(stru, create_color(255, 255, 255), x, y--);
			else
				put_pixel(stru, create_color(0, 0, 0), x, y--);
		}
		x--;
	}
	draw_circle(stru, stru->pos_x * 5, stru->pos_y * 5, 5);
}

void	print_struct(t_stru *stru)
{
	int x;
	int y;

	y = 0;
	printf("stru->pos_x %f\n", stru->pos_x);
	printf("stru->pos_y %f\n", stru->pos_y);
	printf("stru->screen_height %d\n", stru->screen_height);
	printf("stru->screen_width %d\n", stru->screen_width);
	printf("stru->map_height %d\n", stru->map_height);
	printf("stru->map_width %d\n", stru->map_width);
	printf("stru->dir_x %f\n", stru->dir_x);
	printf("stru->dir_y %f\n", stru->dir_y);
	printf("stru->plane_x %f\n", stru->plane_x);
	printf("stru->plane_y %f\n", stru->plane_y);
	while (stru->map[y])
	{
		x = 0;
		while (stru->map[y][x])
		{
			printf("%c", stru->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	print_ray(t_stru *stru)
{
	draw_line(stru, stru->pos_x * 5, stru->pos_y * 5, stru->pos_x * 5 + \
	(stru->raydir_x * 20), stru->pos_y * 5 + (stru->raydir_y * 20), \
	create_color(244, 143, 228));
}
