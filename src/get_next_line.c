/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:50:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/18 09:51:12 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*res;
	size_t			count;

	res = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*res++ = c;
		count++;
	}
	return (s);
}

void	*ft_calloc(size_t nb, size_t size)
{
	unsigned char *res;

	if (!(res = malloc(size * nb)))
		return (NULL);
	ft_memset(res, 0, nb * size);
	return (res);
}

int		ft_len_line(const char *stock)
{
	int i;

	i = 0;
	while (stock && stock[i] && stock[i] != '\n')
		i++;
	return (i);
}

int		ft_loop(char **stock, int fd, char *buffer)
{
	int rd;

	rd = 1;
	while (!ft_strchr(*stock, '\n') && (rd = read(fd, buffer, BUFFER_SIZE)))
	{
		if (rd == -1)
			return (-1);
		buffer[rd] = '\0';
		if (!(*stock = ft_strjoin_free(*stock, buffer, 1)))
			return (-1);
	}
	return (rd);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	int			ret;
	int			i;
	char		*tmp;
	char		*buffer;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!stock)
		stock = ft_calloc(1, 1);
	if ((ret = ft_loop(&stock, fd, buffer)) == -1)
		return (-1);
	free(buffer);
	i = ft_len_line(stock);
	tmp = stock;
	*line = ft_substr(stock, 0, i);
	if (stock[i] == '\n')
		stock = ft_strdup(stock + i + 1);
	else
		stock = NULL;
	if (tmp)
		free(tmp);
	return (((stock == NULL) && !ret && !ft_strlen(*line)) ? 0 : 1);
}
