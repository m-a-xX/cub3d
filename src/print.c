/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:08:09 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/07 02:08:16 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_pixel(t_stru *stru, t_color color, int x, int y)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= stru->screenWidth || y < 0 || y >= stru->screenHeight)
		return ;
	pixel_index = x + (y * stru->screenWidth);
	rel_pixel_index = pixel_index * 4;
	stru->pixels[rel_pixel_index + RED_VALUE] = color.r;
	stru->pixels[rel_pixel_index + GREEN_VALUE] = color.g;
	stru->pixels[rel_pixel_index + BLUE_VALUE] = color.b;
}
