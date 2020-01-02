/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:44:41 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/07 00:09:05 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nb_len(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int		min(char *res)
{
	res[1] = '2';
	return (147483648);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		count;
	int		neg;

	count = nb_len(n);
	neg = 0;
	if (n < 0)
		neg = 1;
	if (!(res = malloc(sizeof(char) * (count + 1 + neg))))
		return (NULL);
	res[count + neg] = '\0';
	if (neg)
		res[0] = '-';
	if (n == -2147483648)
		n = min(res);
	if (n < 0)
		n *= -1;
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		res[count-- - 1 + neg] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
