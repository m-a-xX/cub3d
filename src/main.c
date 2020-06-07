/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/06/07 10:23:33 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		cub3d(t_stru *stru)
{
	init_mlx(stru);
	if (init_textures(stru))
	{
		ft_putstr_fd("Error\nTextures can't be loaded\n", 1);
		return (1);
	}
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
int		open_cub_file(char **av)
{
	int i;

	if (!av[1] || !*av[1])
		return (-1);
	i = ft_strlen(av[1]) - 4;
	if (ft_strncmp(av[1] + i, ".cub", 4))
		return (-1);
	return (open(av[1], O_RDONLY));
}
int		main(int ac, char **av)
{
	int		fd;
	t_stru	*stru;

	if ((ac != 2 && ac != 3) || (!(stru = malloc_struct())))
		return (1);
	if (check_save(av, stru))
		return (1);
	if ((fd = open_cub_file(av)) == -1)
	{
		ft_putstr_fd("Error\nCan't open the settings file\n", 1);
		return (1);
	}
	if (parse_cub(fd, stru))
	{
		free_struct(stru, 0);
		return (1);
	}
	cub3d(stru);
	free_struct(stru, 1);
	return (0);
}
