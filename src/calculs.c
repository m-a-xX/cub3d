/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:27:35 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/12 01:55:47 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calcul_dist_screen(t_stru *stru)
{
	stru->dist_screen = stru->res.x / tan_deg(FOV / 2);
}

void	calcul_map_size(t_stru *stru)
{
	int y;

	y = 0;
	while (stru->map[y])
		y++;
	stru->map_size.x = ft_strlen(stru->map[0]);
	stru->map_size.y = y;
}

void	calcul_sprite_len(t_stru *stru)
{
	stru->len_sprite.x = stru->res.x / (stru->map_size.x);
	stru->len_sprite.y = stru->res.y / (stru->map_size.y);
}

double	d_pythagore(t_vect a, t_vect b)
{
	return (sqrt(pow((double)(b.x - a.x), 2) + pow((double)(b.y - a.y), 2)));
}

int		convert_colors(t_color color)
{
	unsigned char converter[4];

	converter[0] = color.b;
	converter[1] = color.g;
	converter[2] = color.r;
	converter[3] = 0;
	return(*((int *)converter));
}
