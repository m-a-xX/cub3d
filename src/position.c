/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:56:47 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/14 20:04:38 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		rotation(t_stru *stru, int right)
{
	if (right)
		stru->angle += 10;
	else
		stru->angle -= 10;
	if (stru->angle > 360)
		stru->angle = stru->angle - 360;
	else if (stru->angle < 0)
		stru->angle = 360 - abs((int)stru->angle);
	stru->orient.x = cos(deg_to_rad(stru->angle)) * 8;
	stru->orient.y = sin(deg_to_rad(stru->angle)) * 8;
	return (0);
}

int		check_wall(t_stru *stru)
{
	t_vect p;

	p = div_vects(stru->pixel_pos, stru->len_sprite);
	if (stru->map[p.y][p.x] == '0' || ft_strchr("SNEW", stru->map[p.y][p.x]))
		return (0);
	return (1);
}

int		actualise_pos(t_stru *stru)
{
	stru->pixel_pos = add_vects(stru->pixel_pos, stru->move);
	if (check_wall(stru))
	{
		stru->pixel_pos = sub_vects(stru->pixel_pos, stru->move);
		return (1);
	}
	return (0);
}
