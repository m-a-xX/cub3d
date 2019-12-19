/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_free_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 00:58:13 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/19 02:24:30 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*strjoin_free_nl(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		count;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	count = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (NULL);
	len = 0;
	while (s1[count])
		res[len++] = s1[count++];
	count = 0;
	while (s2[count])
		res[len++] = s2[count++];
	res[len++] = '\n';
	res[len] = 0;
	free(s1);
	free(s2);
	return (res);
}
