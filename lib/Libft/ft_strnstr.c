/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:37:41 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/06 08:31:04 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		is_find(const char *s1, const char *s2, size_t len, size_t count)
{
	int c;

	c = 0;
	while (s1[count] && s2[c] && count < len && s1[count] == s2[c])
	{
		count++;
		c++;
	}
	if (s2[c] == 0)
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t count;

	count = 0;
	if (!(*s2))
		return ((char *)s1);
	while (s1[count] && count < len)
	{
		if (s1[count] != s2[0])
			count++;
		else
		{
			if (is_find(s1, s2, len, count))
				return ((char *)s1 + count);
			count++;
		}
	}
	return (NULL);
}
