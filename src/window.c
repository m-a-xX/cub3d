/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:53:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/05 20:12:18 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		key_hook(int keyhook, t_stru *stru)
{
	t_color color = create_color(255, 24, 255);

	char *s = ft_itoa_base(keyhook, "0123456789");
	write(1, "key", 3);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	mlx_string_put(stru->mlx_ptr, stru->win_ptr, 10, 10, convert_colors(color), s);
	if (keyhook == 13)
		stru->pos.y -= 1;
	if (keyhook == 1)
		stru->pos.y += 1;
	if (keyhook == 0)
		stru->pos.x -= 1;
	if (keyhook == 2)
		stru->pos.x += 1;
	//if (keyhook == 123)
		//stru->angle += 1;
	//if (keyhook == 124)
		//stru->angle -= 1;
	//mlx_clear_window(stru->mlx_ptr, stru->win_ptr);
	draw_circle(stru, create_vect(stru->pos.x * stru->len_sprite.x, stru->pos.y * stru->len_sprite.y), color, 15);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);
}

int		cub3d(t_stru *stru)
{
	stru->mlx_ptr = mlx_init();
	stru->win_ptr = mlx_new_window(stru->mlx_ptr, stru->res.x,
	stru->res.y, "cub3d");
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, stru->res.x, stru->res.y);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp), &(stru->sizeline), &(stru->endian));
	t_color color = create_color(255, 24, 255);
	t_vect a = create_vect(200, 0);
	t_vect b = create_vect(0, 200);
	t_vect c = create_vect(200, 200);
	calcul_dist_screen(stru);
	calcul_sprite_len(stru);
	//draw_rectangle(stru, create_rect(0, 0, stru->res.x, stru->res.y / 2),
	//stru->rgb_sol);
	//draw_line(stru, create_vect(12, 45), create_vect(265, 364), color);
	//draw_circle(stru, create_vect(stru->pos.x * stru->len_sprite.x, stru->pos.y * stru->len_sprite.y), color, 2);
	//draw_triangle(stru, create_triangle(a, b, c), stru->rgb_plafond);
	//put_pixel(stru, color, 65, 35);
	/* draw_rectangle(stru, create_rect(0, stru->res.y / 2, stru->res.x, stru->res.y),
	stru->rgb_plafond);
	draw_rectangle(stru, create_rect(10, 100, 390, 300), */
	//draw_line(stru, create_vect(10, 10), create_vect(300, 300), create_color(255, 255, 255));
	//mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	printf("ok");
	mlx_key_hook(stru->win_ptr, key_hook, stru);
	printf("x %d", stru->pos.x);
	mlx_loop(stru->mlx_ptr);
	return (0);
}