/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:50:43 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/06 09:12:40 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;

	count = 0;
	while (count < n)
	{
		((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
		if (((unsigned char *)dst)[count] == (unsigned char)c)
			return (dst + count + 1);
		count++;
	}
	return (NULL);
}
