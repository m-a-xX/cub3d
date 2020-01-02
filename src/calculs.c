/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:27:35 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/02 11:06:51 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calcul_dist_screen(t_stru *stru)
{
	stru->dist_screen = stru->res_x / tan_deg(30);
}

void	calcul_center(t_stru *stru)
{
	stru->center_y = stru->res_x / 2;
	stru->center_y = stru->res_y / 2;
}

int		