/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:13:18 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/06 01:37:20 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	{
		while (*s != (char)c)
			s++;
	}
	return ((char *)s);
}
