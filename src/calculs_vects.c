/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_vects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 00:58:30 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/12 20:24:10 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

t_vect	sub_vects(t_vect v1, t_vect v2)
{
	t_vect res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}
