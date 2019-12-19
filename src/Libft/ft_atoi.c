/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:02:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/06 00:40:54 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nb)
{
	int count;
	int res;
	int neg;

	count = 0;
	neg = 1;
	res = 0;
	while ((nb[count] >= 8 && nb[count] <= 13) || nb[count] == ' ')
		count++;
	if (nb[count] == '+')
		count++;
	else if (nb[count] == '-')
	{
		count++;
		neg *= -1;
	}
	while (nb[count] >= '0' && nb[count] <= '9')
	{
		res = res * 10 + nb[count] - 48;
		count++;
	}
	return (res * neg);
}
