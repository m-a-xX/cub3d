/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/07 02:27:06 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_stru	create_struct(void)
{
	t_stru to_create;

	to_create.map = NULL;
	to_create.pathNorth = NULL;
	to_create.pathEst = NULL;
	to_create.pathSouth = NULL;
	to_create.pathWest = NULL;
	to_create.pathSprite = NULL;
	to_create.mlx_ptr = NULL;
	to_create.img_ptr = NULL;
	to_create.win_ptr = NULL;
	to_create.pixels = NULL;
	to_create.moveSpeed = 0.3;
	to_create.rotSpeed = 0.5;
	return (to_create);
}

t_stru	*malloc_struct(void)
{
	t_stru *to_malloc;

	if (!(to_malloc = malloc(sizeof(t_stru))))
		return (NULL);
	*to_malloc = create_struct();
	return (to_malloc);
}

void	free_struct(t_stru *to_free)
{
	if (to_free->map)
		free(to_free->map);
	if (to_free->pathNorth)
		free(to_free->pathNorth);
	if (to_free->pathEst)
		free(to_free->pathEst);
	if (to_free->pathSouth)
		free(to_free->pathSouth);
	if (to_free->pathWest)
		free(to_free->pathWest);
	if (to_free->pathSprite)
		free(to_free->pathSprite);
	free(to_free);
}

t_color	create_color(int r, int b, int g)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

