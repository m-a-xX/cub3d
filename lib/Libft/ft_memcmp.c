/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:14:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/07 02:13:29 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	size_t			count;

	count = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (count < n && u1[count] == u2[count])
		count++;
	if (count == n)
		return (0);
	return (u1[count] - u2[count]);
}
