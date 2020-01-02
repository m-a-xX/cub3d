/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_structs_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/02 15:33:28 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_color	create_color(int r, int b, int g)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_rect	create_rect(int x, int y, int vect_x, int vect_y)
{
	t_rect rect;

	rect.x = x;
	rect.y = y;
	rect.vect_x = vect_x;
	rect.vect_y = vect_y;
	return (rect);
}

t_coord	create_coord(int x, int y)
{
	t_coord coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}
