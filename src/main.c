/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/06/06 21:33:04 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		cub3d(t_stru *stru)
{
	init_mlx(stru);
	init_textures(stru);
	raycast(stru);
	if (stru->save)
	{
		save(stru);
		return (0);
	}
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
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
	if (av[2])
	{
		if (!ft_strncmp(av[2], "--save", 6))
			stru->save = 1;
		else
		{
			ft_putstr_fd("Error\nUnknown second argument\n", 1);
			return (1);
		}
	}
	fd = open(av[1], O_RDONLY);
	if (parse_cub(fd, stru))
		return (1);
	cub3d(stru);
	free_struct(stru);
	return (0);
}
