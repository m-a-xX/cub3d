/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:10:42 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/12 06:06:47 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	size_t	words;
	size_t	count;

	count = 0;
	words = 0;
	while (s[count])
	{
		while (s[count] && s[count] == c)
			count++;
		if (s[count] != c && s[count])
			words++;
		while (s[count] && s[count] != c)
			count++;
	}
	return (words);
}

static char		*ft_strncapy(char *dest, char const *src, size_t n)
{
	size_t count;

	count = 0;
	while (count < n && src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

static char		*ft_strduper(char const *str, char c)
{
	char	*s;
	size_t	count;

	count = 0;
	while (str[count] && str[count] != c)
		count++;
	if (!(s = malloc(sizeof(char) * (count + 1))))
		return (0);
	s = ft_strncapy(s, str, count);
	return (s);
}

static int		ft_free(char **tab, int size)
{
	int count;

	count = 0;
	while (size >= count)
	{
		free(tab[count]);
		count++;
	}
	free(tab);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	tab[2];

	tab[0] = 0;
	tab[1] = ft_countwords(s, c);
	if (!(res = malloc(sizeof(char *) * (tab[1] + 1))))
		return (0);
	res[tab[1]] = 0;
	tab[1] = 0;
	while (s[tab[0]])
	{
		while (s[tab[0]] && s[tab[0]] == c)
			tab[0]++;
		if (s[tab[0]] != c && s[tab[0]])
		{
			if (!(res[tab[1]] = ft_strduper((s + tab[0]), c)))
				if (ft_free(res, tab[1]))
					return (0);
			tab[1]++;
		}
		while (s[tab[0]] && s[tab[0]] != c)
			tab[0]++;
	}
	return (res);
}
