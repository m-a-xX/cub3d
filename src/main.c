/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 05:25:28 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/01 01:33:20 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		print_window(void *mlx_p, t_stru *stru)
{
	void	*win_p;
	int		rgb_sol;
	int		rgb_plafond;
	int		centre_ecran_x;
	int		centre_ecran_y;
	int		d_cam;
	
	centre_ecran_x = stru->res_x / 2;
	centre_ecran_y = stru->res_y / 2;
	d_cam = 
	rgb_sol = (256 * 256 * stru->r_sol) + (256 * stru->g_sol) + stru->b_sol;
	rgb_sol = (256 * 256 * stru->r_plaf) + (256 * stru->g_plaf) + stru->b_plaf;
	if (!(win_p = mlx_new_window(mlx_p, stru->res_x, stru->res_y, "cub3d")))
		return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_stru	*stru;
	void	*mlx_p;

	if (ac != 2)
		return (0);
	if (!(stru = malloc_struct()))
		return (1);
	fd = open(av[1], O_RDONLY);
	parse_cub(fd, stru);
 	if (!(mlx_p = mlx_init()))
	 	return (1);
 	printf("dep pos %c\n", stru->dep_pos);
 	printf("dep x %d\n", stru->dep_x);
 	printf("dep y %d\n", stru->dep_y);
 	printf("res x %d\n", stru->res_x);
	printf("res y %d\n", stru->res_y);
	printf("r_sol %d\n", stru->r_sol);
	printf("g_sol %d\n", stru->g_sol);
	printf("b_sol %d\n\n", stru->b_sol);
	printf("r_plafond %d\n", stru->r_plaf);
	printf("g_plaf %d\n", stru->g_plaf);
	printf("b_plaf %d\n", stru->b_plaf);
	printf("path_nord %s\n", stru->path_nord);
	printf("path_sud %s\n", stru->path_sud);
	printf("map %s\n", stru->map[0]);
	printf("map %s\n", stru->map[1]);
	free_struct(stru);
	return (0);
}

/* int		main(int ac, char **av)
{
	int		fd;
	t_stru	*stru;

	if (ac != 2)
		return (0);
	if (!(stru = malloc(sizeof(t_stru))))
		return (1);
	fd = open(av[1], O_RDONLY);
	parse_cub(fd, stru);
 	printf("dep pos %c\n", stru->dep_pos);
 	printf("dep x %d\n", stru->dep_x);
 	printf("dep y %d\n", stru->dep_y);
 	printf("res x %d\n", stru->res_x);
	printf("res y %d\n", stru->res_y);
	printf("r_sol %d\n", stru->r_sol);
	printf("g_sol %d\n", stru->g_sol);
	printf("b_sol %d\n\n", stru->b_sol);
	printf("r_plafond %d\n", stru->r_plaf);
	printf("g_plaf %d\n", stru->g_plaf);
	printf("b_plaf %d\n", stru->b_plaf);
	printf("path_nord %s\n", stru->path_nord);
	printf("path_sud %s\n", stru->path_sud);
	printf("map %s\n", stru->map[0]);
	printf("map %s\n", stru->map[1]);
	free(stru);
	return (0);
} */
