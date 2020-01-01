/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:12:49 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/01 01:26:47 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_stru	create_struct(void)
{
	t_stru to_create;

	to_create.map = NULL;
	to_create.dep_pos = 0;
	to_create.dep_x = 0;
	to_create.dep_y = 0;
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