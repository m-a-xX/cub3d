/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 05:25:28 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/02 10:56:44 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	int		fd;
	t_stru	*stru;

	if (ac != 2 || (!(stru = malloc_struct())))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (parse_cub(fd, stru))
		return (1);
	cub3d(stru);
	free_struct(stru);
	return (0);
}
