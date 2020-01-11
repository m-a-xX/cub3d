/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 05:25:28 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/11 18:18:35 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	int		fd;
	t_stru	*stru;

	if ((ac != 2 && ac != 3) || (!(stru = malloc_struct())))
		return (1);
	if (av[2] && ft_strncmp(av[2], "-save", ft_strlen(av[2])))
		save_image();
	fd = open(av[1], O_RDONLY);
	if (parse_cub(fd, stru))
		return (1);
	//printf("map x %\n", (double)(stru->pos.x) * (double)(stru->len_sprite.x));
	//printf("map y %\n", (double)(stru->pos.y) * (double)(stru->len_sprite.y));
	calcul_map_size(stru);
	calcul_sprite_len(stru);
	calcul_res_rep(stru);
	cub3d(stru);
	//printf("sprite x %d\n", stru->len_sprite.x);
	//printf("pyth %f\n", d_pythagore(create_vect(0, 0), create_vect(10, 10)));
	free_struct(stru);
	return (0);
}
//GERER SI IL MANQUE UN CHIFFRE POUR LES RGB
