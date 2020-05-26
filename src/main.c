/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/05/26 21:08:12 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		init_textures(t_stru *stru)
{
	int x = 255, y = 255;
	stru->img[0].img_ptr = mlx_xpm_file_to_image(stru->mlx_ptr, "textures/wall1.xpm", &x, &y);
	stru->img[0].pixels = (int *)mlx_get_data_addr(stru->img[0].img_ptr, &(stru->img[0].bpp), &(stru->img[0].sizeline), &(stru->img[0].endian));
	//mlx_destroy_image(stru->mlx_ptr, stru->img_ptr);
	return (0);
}

int		cub3d(t_stru *stru)
{
	init_mlx(stru);
	init_textures(stru);

	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img[0].img_ptr, 300, 300);
	mlx_hook(stru->win_ptr, 2, 1L << 0, key_hook, stru);
	mlx_hook(stru->win_ptr, 17, 1L << 17, exit_hook, stru);
	mlx_loop(stru->mlx_ptr);
	return (0);
}

int		main(int ac, char **av)
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
