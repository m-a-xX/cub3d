/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:00:12 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/09 03:31:32 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strjoin_free(char *s1, char *s2, int c)
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
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	len = 0;
	while (s1[count])
		res[len++] = s1[count++];
	count = 0;
	while (s2[count])
		res[len++] = s2[count++];
	res[len] = 0;
	if (c == 1 || c == 3)
		free(s1);
	if (c == 2 || c == 3)
		free(s2);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (c)
	{
		while (*s && *s != (char)c)
			s++;
		if (!(*s))
			return (NULL);
	}
	else
		while (*s != (char)c)
			s++;
	return ((char *)s);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	int		count;

	count = 0;
	if (!(res = malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[count])
	{
		res[count] = s[count];
		count++;
	}
	res[count] = 0;
	return (res);
}
