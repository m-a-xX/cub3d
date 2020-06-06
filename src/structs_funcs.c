/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/06 23:36:36 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_stru	create_struct(void)
{
	t_stru to_create;

	to_create.map = NULL;
	to_create.path_north = NULL;
	to_create.path_est = NULL;
	to_create.path_south = NULL;
	to_create.path_west = NULL;
	to_create.path_sprite = NULL;
	to_create.mlx_ptr = NULL;
	to_create.img_ptr = NULL;
	to_create.win_ptr = NULL;
	to_create.pixels = NULL;
	to_create.move_speed = 0.1;
	to_create.rot_speed = 0.1;
	to_create.save = 0;
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
	int y;

	y = 0;
	mlx_destroy_window(to_free->mlx_ptr, to_free->win_ptr);
	while (y <= to_free->map_height)
		free(to_free->map[y++]);
	free(to_free->map);
	free(to_free->path_north);
	free(to_free->path_est);
	free(to_free->path_south);
	free(to_free->path_west);
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

t_vect	create_vect(int x, int y)
{
	t_vect vect;

	vect.x = x;
	vect.y = y;
	return (vect);
}
