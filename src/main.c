/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 05:25:28 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/26 17:43:36 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	p_value(int value, char *str)
{
	ft_putnbr_fd(value, 1);
	ft_putstr_fd(str, 1);
}

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
	calcul_map_size(stru);
	calcul_sprite_len(stru);
	p_value(stru->map_size.x, " : x\n");
	p_value(stru->map_size.y, " : y\n");
	cub3d(stru);
	free_struct(stru);
	return (0);
}
//GERER SI IL MANQUE UN CHIFFRE POUR LES RGB
