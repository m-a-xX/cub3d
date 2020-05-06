/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:28:21 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/07 00:22:28 by mavileo          ###   ########.fr       */
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
	stru->win_ptr = mlx_new_window(stru->mlx_ptr, stru->w,
	stru->h, "cub3d");
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, stru->w, stru->h);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp),
	&(stru->sizeline), &(stru->endian));
	return (0);
}

int             key_hook(int keyhook, t_stru *stru)
{
        if (keyhook == UP)
        {
                stru->move.y = stru->orient.y;
                stru->move.x = stru->orient.x;
        }
        else if (keyhook == 1)
        {
                stru->move.y = -stru->orient.y;
                stru->move.x = -stru->orient.x;
        }
        else if (keyhook == LEFT)
        {
                stru->move.x = stru->orient.y;
                stru->move.y = -stru->orient.x;
        }
        else if (keyhook == DOWN)
        {
                stru->move.x = -stru->orient.y;
                stru->move.y = stru->orient.x;
        }
        else if (keyhook == 123)
        {
                stru->move = create_vect(0, 0);
                rotation(stru, 0);
        }
        else if (keyhook == 124)
        {
                stru->move = create_vect(0, 0);
                rotation(stru, 1);
        }
        else
                return (0);
        //horizontal_intersect(stru, stru->angle);
        actualise_pos(stru);
        expose_hook(stru, keyhook);
        return (0);
}
