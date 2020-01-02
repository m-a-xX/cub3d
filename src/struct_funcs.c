/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/01 21:55:30 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_stru	create_struct(void)
{
	t_stru to_create;

	to_create.map = NULL;
	to_create.dep_pos = 0;
	to_create.pos_x = 0;
	to_create.pos_y = 0;
	to_create.res_x = 0;
	to_create.res_y = 0;
	to_create.r_sol = 0;
	to_create.g_sol = 0;
	to_create.b_sol = 0;
	to_create.r_plaf = 0;
	to_create.g_plaf = 0;
	to_create.b_plaf = 0;
	to_create.path_nord = NULL;
	to_create.path_est = NULL;
	to_create.path_sud = NULL;
	to_create.path_ouest = NULL;
	to_create.path_sprite = NULL;
	to_create.mlx_ptr = NULL;
	to_create.img_ptr = NULL;
	to_create.win_ptr = NULL;
	to_create.pixels = NULL;
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
	if (to_free->path_nord)
		free(to_free->path_nord);
	if (to_free->path_est)
		free(to_free->path_est);
	if (to_free->path_sud)
		free(to_free->path_sud);
	if (to_free->path_ouest)
		free(to_free->path_ouest);
	if (to_free->path_sprite)
		free(to_free->path_sprite);
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

t_rect	create_rect(int x, int y, int vect_x, int vect_y)
{
	t_rect rect;

	rect.x = x;
	rect.y = y;
	rect.vect_x = vect_x;
	rect.vect_y = vect_y;
	return (rect);
}
