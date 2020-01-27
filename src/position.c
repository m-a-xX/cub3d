/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:56:47 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/19 14:36:16 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		begin_pos(t_stru *stru)
{
	if (stru->begin_pos == 'N')
	{
		stru->orient.x = 0;
		stru->orient.y = -(stru->len_sprite.y) / 6;
		stru->angle = 90;
	}
	else if (stru->begin_pos == 'S')
	{
		stru->orient.x = 0;
		stru->orient.y = (stru->len_sprite.y) / 6;
		stru->angle = 270;
	}
	else if (stru->begin_pos == 'E')
	{
		stru->orient.x = (stru->len_sprite.x) / 6;
		stru->orient.y = 0;
		stru->angle = 0;
	}
	else if (stru->begin_pos == 'W')
	{
		stru->orient.x = -(stru->len_sprite.x) / 6;
		stru->orient.y = 0;
		stru->angle = 180;
	}
	return (0);
}

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
	//ft_putnbr_fd((int)stru->angle, 1);
	//ft_putstr_fd("\n", 1);
	//p_value(stru->orient.x, " : orient x\n");
	//p_value(stru->orient.y, " : orient y\n");
	stru->orient.x = cos(deg_to_rad(stru->angle)) * (stru->len_sprite.x) / 6 * -1;
	stru->orient.y = sin(deg_to_rad(stru->angle)) * (stru->len_sprite.y) / 6 * -1;
	//vertical_intersect(stru, stru->angle);
	//horizontal_intersect(stru, stru->angle);
	return (0);
}

int		check_wall(t_stru *stru, t_vect *to_check)
{
	t_vect p;

	if (to_check == NULL)
	{
		p = div_vects(stru->pixel_pos, stru->len_sprite);
		if (stru->map[p.y][p.x] == '0' || ft_strchr("SNEW", stru->map[p.y][p.x]))
			return (0);
		return (1);
	}
	p = div_vects(add_vects(stru->pixel_pos, *to_check), stru->len_sprite);
	if (stru->map[p.y][p.x] == '0' || ft_strchr("SNEW", stru->map[p.y][p.x]))
		return (0);
	return (1);
}

int		actualise_pos(t_stru *stru)
{
	stru->pixel_pos = add_vects(stru->pixel_pos, stru->move);
	if (check_wall(stru, NULL))
	{
		stru->pixel_pos = sub_vects(stru->pixel_pos, stru->move);
		stru->pos.x = stru->pixel_pos.x / stru->len_sprite.x;
		stru->pos.y = stru->pixel_pos.y / stru->len_sprite.y;
		return (1);
	}
	return (0);
}
