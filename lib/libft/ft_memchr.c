/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:00:17 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/11 20:25:36 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			count;

	count = 0;
	tmp = (unsigned char *)s;
	while (count < n)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
		count++;
	}
	return (NULL);
}
