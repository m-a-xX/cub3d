/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_structs_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/12 00:59:57 by mavileo          ###   ########.fr       */
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

t_vect	create_vect(int x, int y)
{
	t_vect vect;

	vect.x = x;
	vect.y = y;
	return (vect);
}

t_rect	create_rect(int x, int y, int vect_x, int vect_y)
{
	t_rect rect;

	rect.dep.x = x;
	rect.dep.y = y;
	rect.end.x = vect_x;
	rect.end.y = vect_y;
	return (rect);
}
