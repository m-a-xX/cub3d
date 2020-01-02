/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:10:23 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/02 11:09:55 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define RED_VALUE 2
# define GREEN_VALUE 1
# define BLUE_VALUE 0
# define POV 60

typedef struct	s_stru
{
	char	**map;
	char	dep_pos;
	int		pos_x;
	int		pos_y;
	int		res_x;
	int		res_y;
	int		r_sol;
	int		g_sol;
	int		b_sol;
	int		r_plaf;
	int		g_plaf;
	int		b_plaf;
	char	*path_nord;
	char	*path_est;
	char	*path_sud;
	char	*path_ouest;
	char	*path_sprite;
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	char	*pixels;
	int		bpp;
	int		sizeline;
	int		endian;
	int		dist_screen;
	int		center_x;
	int		center_y;
}				t_stru;

typedef struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_rect
{
	int x;
	int y;
	int vect_x;
	int vect_y;
}				t_rect;

/* GNL */
int		get_next_line(int fd, char **line);
int		ft_strlen(const char *s);
int		ft_search_nl(char *str);
char	*ft_strjoin_free(char *s1, char *s2, int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nb, size_t size);
int		ft_len_line(const char *stock);
int		ft_loop(char **stock, int fd, char *buffer);
int		ft_atoi(const char *nb);

/* LIBFT */
void	*ft_calloc(size_t nb, size_t size);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_path(char *line, int i);

/* CUB3D */
char	*get_path(char *line, int i);
void	get_rgb(char *line, int i, t_stru *stru, int sol);
int		parse_cub(int fd, t_stru *stru);
int		check_errors(t_stru *stru);
void	init_stru(t_stru *stru);
char	*strjoin_free_nl(char *s1, char *s2);
int		ft_recursive_power(int nb, int power);
void	res(int i, t_stru *stru, char *line);
int		analyse_line(char *line, t_stru *stru, int i);
double	deg_to_rad(double deg);
double	cos_deg(double deg);
double	sin_deg(double deg);
double	tan_deg(double deg);
t_stru	create_struct(void);
t_stru	*malloc_struct(void);
void	free_struct(t_stru *to_free);
int		convert_colors(int r, int b, int g);
t_color	create_color(int r, int b, int g);
void	put_pixel(t_stru *stru, t_color color, int x, int y);
void	draw_rectangle(t_stru *stru, t_rect rect, t_color color);
t_rect	create_rect(int x, int y, int vect_x, int vect_y);
int		cub3d(t_stru *stru);

#endif