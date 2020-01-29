/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:35 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/07 00:42:01 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_list
{
	int				left;
	int				prec;
	int				prec_len;
	int				width;
	int				par_prec;
	int				par_width;
	int				fillzer;
	char			type;
	struct s_list	*next;
}				t_list;

int				ft_printf(const char *str, ...);
int				ft_putchar(char c, int end);
void			ft_putnbr(long nb);
void			ft_putstr(char *str);
int				ft_atoi(const char *nb);
int				ft_isdigit(int c);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *s);
t_list			*ft_newlist(int nb);
int				ft_check_convers(char c, char *list);
int				ft_width_precision(const char *str, int i, t_list *list);
int				ft_type(const char *str, int i, t_list *stru);
int				ft_count_convers(const char *str);
void			ft_print_nb(long nb, t_list *list);
char			*ft_itoa_base(long nb, char *base);
void			ft_putunsign(unsigned int nb);
void			ft_loop(const char *str, t_list *tmp, va_list va_lst);
void			ft_which_type(t_list *list, va_list va_lst);
void			ft_lstclear(t_list **lst);
void			ft_print_c(char c, t_list *list);
void			ft_print_s(char *str, t_list *list);
void			ft_print_x(unsigned int nb, t_list *list);
void			ft_print_p(void *addr, t_list *list);
void			ft_print_u(unsigned int nb, t_list *list);
void			ft_print_pc(char c, t_list *list);
char			*ft_substr(char const *s, int start, int len);

#endif
