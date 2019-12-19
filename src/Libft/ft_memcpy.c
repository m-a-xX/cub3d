/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:34:49 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/06 01:19:57 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	size_t			count;

	if ((!(dst)) && (!(src)))
		return (NULL);
	count = 0;
	tmp = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (count < n)
	{
		*tmp++ = *tmp2++;
		count++;
	}
	return (dst);
}
