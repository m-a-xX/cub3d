/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/27 23:42:56 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_stru	create_struct(void)
{
	t_stru to_create;

	to_create.map = NULL;
	to_create.pos.x = 0;
	to_create.pos.y = 0;
	to_create.res.x = 0;
	to_create.res.y = 0;
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

t_vecf	create_vectf(double x, double y)
{
	t_vecf res;

	res.x = x;
	res.y = y;
	return (res);
}

t_ray	create_ray(t_stru *stru)
{
	t_ray ray;

	ray.x = 0;
	ray.y = 0;
	ray.dir.x = cos_deg(stru->angle);
	ray.dir.y = sin_deg(stru->angle);
	ray.plane.x = -ray.dir.y;
	ray.plane.y = -ray.dir.x;
	ray.pos.x = (double)stru->pixel_pos.x / (double)stru->len_sprite.x;
	ray.pos.y = (double)stru->pixel_pos.y / (double)stru->len_sprite.y;
	ray.map = div_vects(stru->pixel_pos, stru->len_sprite);
	ray.w = stru->res.x;
	ray.h = stru->res.y;
	return (ray);
}
