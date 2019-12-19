/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 05:25:28 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/19 03:00:23 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	int		fd;
	t_stru	*stru;

	if (ac != 2)
		return (0);
	if (!(stru = malloc(sizeof(t_stru))))
		return (1);
	fd = open(av[1], O_RDONLY);
	parse_cub(fd, stru);
 	printf("res x %d\n", stru->res_x);
	printf("res y %d\n", stru->res_y);
	printf("r_sol %d\n", stru->r_sol);
	printf("g_sol %d\n", stru->g_sol);
	printf("b_sol %d\n\n", stru->b_sol);
	printf("r_plafond %d\n", stru->r_plafond);
	printf("g_plafond %d\n", stru->g_plafond);
	printf("b_plafond %d\n", stru->b_plafond);
	printf("path_nord %s\n", stru->path_nord);
	printf("path_sud %s\n", stru->path_sud);
	printf("map %s\n", stru->map[0]);
	printf("map %s\n", stru->map[1]);
	printf("map %s\n", stru->map[2]);
	printf("map %s\n", stru->map[3]);
	free(stru);
	return (0);
}
