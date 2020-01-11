/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:27:35 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/11 15:25:49 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calcul_dist_screen(t_stru *stru)
{
	stru->dist_screen = stru->res.x / tan_deg(POV / 2);
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

void	calcul_res_rep(t_stru *stru)
{
	stru->res_rep.x = stru->map_size.x * 64;
	stru->res_rep.y = stru->map_size.y * 64;
}

int		absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	d_pythagore(t_vect a, t_vect b)
{
	return (sqrt(pow((double)(b.x - a.x), 2) + pow((double)(b.y - a.y), 2)));
}

t_vect	mult_vects(t_vect v1, t_vect mult)
{
	t_vect res;

	res.x = v1.x * mult.x;
	res.y = v1.y * mult.y;
	return (res);
}

t_vect	div_vects(t_vect v1, t_vect div)
{
	t_vect res;

	res.x = v1.x / div.x;
	res.y = v1.y / div.y;
	return (res);
}

t_vect	add_vects(t_vect v1, t_vect v2)
{
	t_vect res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	return (res);
}

t_vect	adapt_to_res(t_vect pos, t_vect len_sprite)
{
	t_vect result;

	result.x = pos.x / 64 * len_sprite.x;
	result.y = pos.y / 64 * len_sprite.y;
	return (result);
}
