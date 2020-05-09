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

int             cub3d(t_stru *stru)
{
 	stru->pos_x = 22;
	stru->pos_y = 11;

	stru->screen_height = 400;
	stru->screen_width = 600;

	stru->map_height = 11;
	stru->map_width = 11;

	stru->dir_x = -1;
	stru->dir_y = 0;
	stru->move_speed = 0.1;
	stru->rot_speed = 0.1;

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
        int             fd;
        t_stru  *stru;

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