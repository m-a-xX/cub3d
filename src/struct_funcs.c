/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/15 22:12:58 by mavileo          ###   ########.fr       */
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

t_vecf	create_vectf(float x, float y)
{
	t_vecf res;
	
	res.x = x;
	res.y = y;
	return (res);
}