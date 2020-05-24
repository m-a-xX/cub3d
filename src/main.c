/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/05/09 03:51:03 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_map(t_stru *stru)
{
	printf("stru->pos_x %f\n", stru->pos_x);
	printf("stru->pos_y %f\n", stru->pos_y);
	printf("stru->screen_height %d\n", stru->screen_height);
	printf("stru->screen_width %d\n", stru->screen_width);
	printf("stru->map_height %d\n", stru->map_height);
	printf("stru->map_width %d\n", stru->map_width);
	printf("stru->dir_x %f\n", stru->dir_x);
	printf("stru->dir_y %f\n", stru->dir_y);
	printf("stru->move_speed %f\n", stru->move_speed);
	printf("stru->rot_speed %f\n", stru->rot_speed);
	printf("stru->plane_x %f\n", stru->plane_x);
	printf("stru->plane_y %f\n", stru->plane_y);
	int x = 0, y = 0;
	while (stru->map[y])
	{
		x = 0;
		while (stru->map[y][x])
		{
			printf("%c", stru->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

int             cub3d(t_stru *stru)
{
	print_map(stru);
	init_mlx(stru);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_hook(stru->win_ptr, 2, 1L<<0, key_hook, stru);
	mlx_hook(stru->win_ptr, 17, 0, exit_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}

int             main(int ac, char **av)
{
	int		fd;
	t_stru	*stru;

	if ((ac != 2 && ac != 3) || (!(stru = malloc_struct())))
		return (1);
	//if (av[2] && ft_strncmp(av[2], "-save", ft_strlen(av[2])))
		//save_image();
	fd = open(av[1], O_RDONLY);
	if (parse_cub(fd, stru))
		return (1);
	cub3d(stru);
	free_struct(stru);
	return (0);
}