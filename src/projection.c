/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 01:59:42 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/11 16:20:00 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_vect	horizontal_intersect(t_stru *stru)
{
	t_vect v;
	int		xa;
	int		ya;

	//if (rayon haut)
	if (1)
	{
		v.y = (int)((stru->pos.y / 64) * 64 - 1);
		ya = -64;
	}
	else
	{
		v.y = (int)((stru->pos.y / 64) * 64 + 64);
		ya = 64;
	}
	v.x = (int)(stru->pos.x + (stru->pos.y / v.y) / tan_deg(60));
	xa = 64 / tan_deg(60);
	while (stru->map[v.x][v.y] != '1' && stru->map[v.x][v.y] != '2')
	{
		v.x = v.x + xa;
		v.y = v.y + ya;
	}
	return (v);
}

t_vect	vertical_intersect(t_stru *stru)
{
	t_vect	v;
	int		xa;
	int		ya;

	//if (rayon gauche)
	if (1)
	{
		v.x = (int)((stru->pos.x / 64) * 64 - 1);
		xa = -64;
	}
	else
	{
		v.x = (int)((stru->pos.x / 64) * 64 + 64);
		xa = 64;
	}
	v.y = (int)(stru->pos.y + (stru->pos.x - v.x) * tan_deg(60));
	ya = 64 * tan_deg(60);
	while (stru->map[v.x][v.y] != '1' && stru->map[v.x][v.y] != '2')
	{
		v.x = v.x + xa;
		v.y = v.y + ya;
	}
	return (v);
}
