/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 21:32:46 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/31 22:08:40 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	deg_to_rad(double deg)
{
	return ((deg) * M_PI / 180);
}

double	cos_deg(double deg)
{
	return (cos(deg_to_rad(deg)));
}

double	sin_deg(double deg)
{
	return (sin(deg_to_rad(deg)));
}

double	tan_deg(double deg)
{
	return (tan(deg_to_rad(deg)));
}