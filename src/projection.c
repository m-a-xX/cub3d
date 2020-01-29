/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 01:59:42 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/29 01:00:57 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	verif_div(double n, double div)
{
	if (div)
		return (n / div);
	return (0);
}

int		render(t_stru *stru, int k)
{
	static int	first = 1;
	t_ray		ray;

	ray = create_ray(stru);
	// la fonction ne s’exécute que si l’écran a besoin d’être rafraîchit
	if (k == 13 || k == 1 || k == 2 || k == 123 || k == 124 || first)
	{
		first = 0;// on a affiché une première fois
		// trace le rendu
		while (ray.x <= ray.w)
		{
			ray.camera_x = (2 * ray.x / ray.w) - 1;
			ray.ray_pos = ray.pos;
			ray.ray_dir.x = ray.dir.x + ray.plane.x * ray.camera_x;
			ray.ray_dir.y = ray.dir.y + ray.plane.y * ray.camera_x;
			ray.delta_dist.x = sqrt(1 + (verif_div((ray.ray_dir.y * ray.ray_dir.y), (ray.ray_dir.x * ray.ray_dir.x))));
			ray.delta_dist.y = sqrt(1 + (verif_div((ray.ray_dir.x * ray.ray_dir.x), (ray.ray_dir.y * ray.ray_dir.y))));
			//calcule le vecteur de direction et la longueur entre deux segments
			if (ray.ray_dir.x < 0)
			{
				ray.step.x = -1;// vecteur de direction
				ray.side_dist.x = (ray.ray_pos.x - ray.map.x) * ray.delta_dist.x;// distance
			}
			else
			{
				ray.step.x = 1;
				ray.side_dist.x = (ray.map.x + 1.0 - ray.ray_pos.x) * ray.delta_dist.x;
			}
			if (ray.ray_dir.y < 0)
			{
				ray.step.y = -1;
				ray.side_dist.y = (ray.ray_pos.y - ray.map.y) * ray.delta_dist.y;
			}
			else
			{
				ray.step.y = 1;
				ray.side_dist.y = (ray.map.y + 1.0 - ray.ray_pos.y) * ray.delta_dist.y;
			}

			// tant que le rayon ne rencontre pas de mur
			while (!ray.hit)
			{

				//Passe à la case suivante sur .x ou Y
				if (ray.side_dist.x < ray.side_dist.y)
				{
					ray.side_dist.x += ray.delta_dist.x;// agrandis le rayon
					ray.map.x += ray.step.x;// prochaine case ou case précédente sur .x
					ray.side = 0;// orientation du mur
				}
				else
				{
					ray.side_dist.y += ray.delta_dist.y;// agrandis le rayon
					ray.map.y += ray.step.y;// prochaine case ou case précédente sur Y
					ray.side = 1;// orientation du mur
				}
				// si le rayon rencontre un mur
				if (stru->map[ray.map.x][ray.map.y] > 0)
					ray.hit = 1;// stoppe la boucle
			}
			// Calcule la distance corrigée pour la projection
			if (!ray.side)
				ray.perp_wall_dist = abs((int)((ray.map.x - ray.ray_pos.x + verif_div((1.0 - ray.step.x) / 2.0, ray.ray_dir.x))));
			else
				ray.perp_wall_dist = abs((int)((ray.map.y - ray.ray_pos.y + verif_div((1.0 - ray.step.y) / 2.0, ray.ray_dir.y))));
			//Calcule la hauteur de la ligne à tracer
			ray.height_line = abs((int)verif_div(ray.h, ray.perp_wall_dist));

			//Calcule les pixels max haut et max bas de la colonne à tracer
			ray.draw_start = (int)-ray.height_line / 2 + (int)ray.h / 2;
			ray.draw_end = (int)ray.height_line / 2 + (int)ray.h / 2;
			// limite les zones de tracé à l'écran uniquement
			if (ray.draw_start < 0)
				ray.draw_start = 0;
			if (ray.draw_end >= ray.h)
				ray.draw_end = ray.h - 1;
			ray.color = create_color(245, 12, 35);
			if (ray.side)
				ray.color = create_color(245, 52, 114);
			draw_line(stru, create_vect(ray.x, ray.draw_start), create_vect(ray.x, ray.draw_end), ray.color);
			ray.x++;
		}
	}
	return (0);
}
