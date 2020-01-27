/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 01:59:42 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/27 23:06:30 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_vect	horizontal_intersect(t_stru *stru, float angle)
{
	t_vect	tmp;
	t_vect	v;
	int		xa;
	int		ya;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	if (angle < 180 || (angle < -180 && angle > -360))
	{
		y1 = stru->map_size.y * (stru->pixel_pos.y / stru->map_size.y);
		ya = -stru->len_sprite.y;
	}
	else
	{
		y1 = stru->map_size.y * (stru->pixel_pos.y / stru->map_size.y + 1);
		ya = stru->len_sprite.y;
	}
	x1 = stru->pixel_pos.x + abs(y1 - stru->pixel_pos.y) / tan_deg(angle);
	y2 = y1 + ya;
	x2 = x1 + ya / tan_deg(angle);
	xa = x2 - x1;
	v = create_vect(x1, x2);
	tmp = div_vects(v, stru->map_size);
	while (stru->map[tmp.x][tmp.y] && stru->map[tmp.x][tmp.y] != '1' && stru->map[tmp.x][tmp.y] != '2')
	{
		v.x += xa;
		v.y += ya;
		tmp = div_vects(v, stru->map_size);
	}
	ft_putnbr_fd(v.x, 1);
	ft_putstr_fd(" : x hor\n", 1);
	ft_putnbr_fd(v.y, 1);
	ft_putstr_fd(" : y hor\n", 1);
	return (v);
}

t_vect	horizontal_intersect(t_stru *stru, float angle)
{
	t_vect	tmp;
	t_vect	v;
	int		xa;
	int		ya;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	if (angle < 180 || (angle < -180 && angle > -360))
	{
		y1 = stru->map_size.y * (stru->pixel_pos.y / stru->map_size.y);
		ya = -stru->len_sprite.y;
	}
	else
	{
		y1 = stru->map_size.y * (stru->pixel_pos.y / stru->map_size.y + 1);
		ya = stru->len_sprite.y;
	}
	x1 = stru->pixel_pos.x + abs(y1 - stru->pixel_pos.y) / tan_deg(angle);
	y2 = y1 + ya;
	x2 = x1 + ya / tan_deg(angle);
	xa = x2 - x1;
	v = create_vect(x1, x2);
	tmp = div_vects(v, stru->map_size);
	while (stru->map[tmp.x][tmp.y] && stru->map[tmp.x][tmp.y] != '1' && stru->map[tmp.x][tmp.y] != '2')
	{
		v.x += xa;
		v.y += ya;
		tmp = div_vects(v, stru->map_size);
	}
	ft_putnbr_fd(v.x, 1);
	ft_putstr_fd(" : x hor\n", 1);
	ft_putnbr_fd(v.y, 1);
	ft_putstr_fd(" : y hor\n", 1);
	return (v);
}

t_vect	vertical_intersect(t_stru *stru, float angle)
{
	t_vect	v;
	int		xa;
	int		ya;

	if (angle > 90 && angle < 270)
	{
		v.x = (int)((stru->pixel_pos.x / stru->len_sprite.x / stru->len_sprite.x) * stru->len_sprite.x - 1);
		xa = -stru->len_sprite.x;
	}
	else
	{
		v.x = (int)((stru->pixel_pos.x / stru->len_sprite.x / stru->len_sprite.x) * stru->len_sprite.x + stru->len_sprite.x);
		xa = stru->len_sprite.x;
	}
	v.y = (int)(stru->pixel_pos.y / stru->len_sprite.y + (stru->pixel_pos.x / stru->len_sprite.x - v.x) * tan_deg(angle));
	ya = stru->len_sprite.y * tan_deg(angle);
	while (stru->map[v.x][v.y] && stru->map[v.x][v.y] != '1' && stru->map[v.x][v.y] != '2')
	{
		v.x = v.x + xa;
		v.y = v.y + ya;
	}
	ft_putnbr_fd(v.x, 1);
	ft_putstr_fd(" : x vert\n", 1);
	ft_putnbr_fd(v.y, 1);
	ft_putstr_fd(" : y vert\n", 1);
	return (v);
}

int		render(int k)
{
	bool	first;
	int		x;// position de départ du tracé de l'écran sur X
	int		y;// position de départ du tracé de l'écran sur Y
	t_vect	pos;
	t_vect	dir;
	t_vect	ray_pos;
	t_vect	ray_dir;
	int		camera_x;
	int		w = 200;
	int		h = 200;
	t_vect	plane;
	
	plane.x = -stru->orient.y;
	plane.y = -stru->orient.x;
	ray_pos = stru->pos;
	ray_dir.x = stru->orient.x + plane.x * camera_x;
	ray_dir.y = stru->orient.y + plane.y * camera_x;
	x = 0;
	y = 0;
	first = true;
	// la fonction ne s’exécute que si l’écran a besoin d’être rafraîchit
	if (k == 13 || k == 1 || k == 0 || k == 2 || k == 123 || k == 124 || first)
	{
		first = false;// on a affiché une première fois
		screen.lock();// bloque la mise à jour des bitmaps dans la zone de jeu
		bouge();// modifie les paramètres
		// trace le rendu
		while (x <= w)
		{
			camera_x = (2 * x / w) - 1;
			ray_pos.x = pos.x;
			ray_pos.y = pos.y;
			ray_dir = 
		}
		screen.unlock();// débloque la mise à jour des bitmaps dans l'écran de jeu
	}
}
