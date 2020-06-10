/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 09:39:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/06/10 02:48:00 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		check_keys(char *line, int i)
{
	static int	keys[8] = {0, 0, 0, 0, 0, 0, 0};
	int			j;

	j = 0;
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		keys[0]++;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		keys[1]++;
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		keys[2]++;
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		keys[3]++;
	if (line[i] == 'S' && line[i + 1] == ' ')
		keys[4]++;
	if (line[i] == 'F' && line[i + 1] == ' ')
		keys[5]++;
	if (line[i] == 'C' && line[i + 1] == ' ')
		keys[6]++;
	if (line[i] == 'R' && line[i + 1] == ' ')
		keys[7]++;
	j = 0;
	while (j < 8)
		if (keys[j++] > 1)
			return (1);
	return (0);
}

int		map_and_check(t_stru *stru, int fd)
{
	char *map;

	map = map_to_str(fd);
	if (tab_to_matrix(stru, map))
		return (error_parsing(3));
	free(map);
	if (check_stru(stru))
		return (error_parsing(4));
	if (check_map(stru))
		return (error_parsing(5));
	begin_plane(stru);
	return (0);
}
