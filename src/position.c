/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:56:47 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/12 00:57:07 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		orientation(t_stru *stru, int right)
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

int		actualise_pos(t_stru *stru)
{
	stru->pixel_pos = add_vects(stru->pixel_pos, stru->move);
	if (stru->pixel_pos.x < stru->len_sprite.x)
		stru->pixel_pos.x -= stru->move.x;
	if (stru->pixel_pos.y < stru->len_sprite.y)
		stru->pixel_pos.y -= stru->move.y;
	if (stru->pixel_pos.x > stru->res.x - stru->len_sprite.x)
		stru->pixel_pos.x -= stru->move.x;
	if (stru->pixel_pos.y > stru->res.y - stru->len_sprite.y)
		stru->pixel_pos.y -= stru->move.y;
	return (0);
}
