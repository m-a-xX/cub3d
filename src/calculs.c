/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:27:35 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/02 15:33:09 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calcul_dist_screen(t_stru *stru)
{
	stru->dist_screen = stru->res_x / tan_deg(30);
}

void	calcul_center(t_stru *stru)
{
	stru->center_y = stru->res_x / 2;
	stru->center_y = stru->res_y / 2;
}
/* 
t_coord	horizontal_intersect(t_stru *stru)
{
	t_coord inter;

	if (rayon haut)
	{
		inter.y = (int)((stru->pos_y / 64) * 64 - 1);
		inter.x = (int)(stru->pos_x + (stru->pos_y / 64) * 64 - 1);
	}
} */