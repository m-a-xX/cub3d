/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:44:03 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/13 04:26:07 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_set(char c, char const *set)
{
	int count;

	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		stop;
	int		count;

	start = 0;
	count = 0;
	if (!s1 || !*s1)
		return (ft_strdup(""));
	if (!*set || !set)
		return (ft_strdup(s1));
	while (is_set(s1[start], set))
		start++;
	stop = ft_strlen(s1) - 1;
	while (is_set(s1[stop], set) && stop > start)
		stop--;
	stop++;
	if (start >= stop)
		return (ft_strdup(""));
	if (!(res = malloc(sizeof(char) * (stop - start + 1))))
		return (NULL);
	while (start < stop)
		res[count++] = s1[start++];
	res[count] = '\0';
	return (res);
}
