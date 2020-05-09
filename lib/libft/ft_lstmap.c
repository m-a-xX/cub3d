/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 03:33:30 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/13 04:36:21 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list **res;
	t_list *tmp;
	t_list *tmp_res;

	if (!lst)
		return (NULL);
	if (!(res = malloc(sizeof(t_list) * ft_lstsize(lst))))
		return (NULL);
	tmp = *res;
	while (lst)
	{
		tmp_res = f(lst);
		if (!tmp_res)
			ft_lstdelone(tmp_res, del);
		else
		{
			tmp = tmp_res;
			lst = lst->next;
		}
	}
	return (*res);
}
