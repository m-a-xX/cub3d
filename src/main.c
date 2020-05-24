/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/05/24 23:06:05 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		cub3d(t_stru *stru)
{
	print_struct(stru);
	init_mlx(stru);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	mlx_hook(stru->win_ptr, 2, 1L<<0, key_hook, stru);
	mlx_hook(stru->win_ptr, 17, 1L<<17, exit_hook, stru);
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