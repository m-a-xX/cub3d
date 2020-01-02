/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:49:19 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/07 03:25:47 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_s;
	char	*c_d;
	size_t	count;

	if (src == dst)
		return (dst);
	c_s = (char *)src;
	c_d = (char *)dst;
	if (src < dst)
	{
		count = len;
		while (count-- > 0)
			c_d[count] = c_s[count];
	}
	else
	{
		count = 0;
		while (count < len)
		{
			c_d[count] = c_s[count];
			count++;
		}
	}
	return (dst);
}
