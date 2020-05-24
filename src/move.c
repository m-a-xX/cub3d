/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:30:36 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/09 03:44:53 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		verify_move(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	vertical_move(int keyhook, t_stru *stru)
{
	if (keyhook == UP)
	{
		if (verify_move(stru->map[(int)(stru->pos_x + stru->dir_x * stru->move_speed)][(int)(stru->pos_y)]))
			stru->pos_x += stru->dir_x * stru->move_speed;
		if (verify_move(stru->map[(int)(stru->pos_x)][(int)(stru->pos_y + stru->dir_y * stru->move_speed)]))
			stru->pos_y += stru->dir_y * stru->move_speed;
	}
	else if (keyhook == DOWN)
	{
		if (verify_move(stru->map[(int)(stru->pos_x - stru->dir_x * stru->move_speed)][(int)(stru->pos_y)]))
			stru->pos_x -= stru->dir_x * stru->move_speed;
		if (verify_move(stru->map[(int)(stru->pos_x)][(int)(stru->pos_y - stru->dir_y * stru->move_speed)]))
			stru->pos_y -= stru->dir_y * stru->move_speed;
	}
}

void	horizontal_move(int keyhook, t_stru *stru)
{
	if (keyhook == LEFT)
	{
		if (verify_move(stru->map[(int)(stru->pos_x - stru->plane_x  * stru->rot_speed)][(int)(stru->pos_y)]))
			stru->pos_x -= stru->plane_x * stru->rot_speed;
		if (verify_move(stru->map[(int)(stru->pos_x)][(int)(stru->pos_y - stru->plane_y * stru->rot_speed)]))
			stru->pos_y -= stru->plane_y * stru->rot_speed;
	}
	else if (keyhook == RIGHT)
	{
		if (verify_move(stru->map[(int)(stru->pos_x + stru->plane_x  * stru->rot_speed)][(int)(stru->pos_y)]))
			stru->pos_x += stru->plane_x * stru->rot_speed;
		if (verify_move(stru->map[(int)(stru->pos_x)][(int)(stru->pos_y + stru->plane_y * stru->rot_speed)]))
			stru->pos_y += stru->plane_y * stru->rot_speed;
	}
}

void	rotation(int keyhook, t_stru *stru)
{
	double olddir_x;
	double oldplane_x;

	if (keyhook == ARROW_LEFT)
	{
		olddir_x = stru->dir_x;
		stru->dir_x = stru->dir_x * cos(-stru->rot_speed) - stru->dir_y * sin(-stru->rot_speed);
		stru->dir_y = olddir_x * sin(-stru->rot_speed) + stru->dir_y * cos(-stru->rot_speed);
		oldplane_x = stru->plane_x;
		stru->plane_x = stru->plane_x * cos(-stru->rot_speed) - stru->plane_y * sin(-stru->rot_speed);
		stru->plane_y = oldplane_x * sin(-stru->rot_speed) + stru->plane_y * cos(-stru->rot_speed);
	}
	else if (keyhook == ARROW_RIGHT)
	{
		olddir_x = stru->dir_x;
		stru->dir_x = stru->dir_x * cos(stru->rot_speed) - stru->dir_y * sin(stru->rot_speed);
		stru->dir_y = olddir_x * sin(stru->rot_speed) + stru->dir_y * cos(stru->rot_speed);
		oldplane_x = stru->plane_x;
		stru->plane_x = stru->plane_x * cos(stru->rot_speed) - stru->plane_y * sin(stru->rot_speed);
		stru->plane_y = oldplane_x * sin(stru->rot_speed) + stru->plane_y * cos(stru->rot_speed);
	}
}

int		key_hook(int keyhook, t_stru *stru)
{
	printf("%d\n", keyhook);
	printf("%f %f\n", stru->pos_x, stru->pos_y);
	if (keyhook == ESC)
		exit_hook(stru);
	vertical_move(keyhook, stru);
	horizontal_move(keyhook, stru);
	rotation(keyhook, stru);
	clear(stru);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);	clear(stru);
}
