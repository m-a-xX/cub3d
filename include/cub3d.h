/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 03:10:23 by mavileo           #+#    #+#             */
/*   Updated: 2020/01/05 20:04:06 by mavileo          ###   ########.fr       */
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
# define RAY_LEN 200
# define SPEED_MOOVE 200
# define ANGLE_MOOVE 100

typedef struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_vect
{
	int x;
	int y;
}				t_vect;

typedef struct	s_rect
{
	t_vect dep;
	t_vect end;
}				t_rect;

typedef struct	s_tri
{
	t_vect a;
	t_vect b;
	t_vect c;
}				t_tri;

typedef struct	s_stru
{
	char	**map;
	t_vect	pos;
	t_vect	res;
	t_color	rgb_sol;
	t_color	rgb_plafond;
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
	t_vect	len_sprite;
	float	angle;
	int		key_hook;
	t_vect	res_rep;
	t_vect	map_size;
}				t_stru;

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
t_color	get_rgb(char *line, int i);
int		parse_cub(int fd, t_stru *stru);
int		check_stru(t_stru *stru);
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
int		convert_colors(t_color color);
t_color	create_color(int r, int b, int g);
void	put_pixel(t_stru *stru, t_color color, int x, int y);
void	draw_rectangle(t_stru *stru, t_rect rect, t_color color);
t_rect	create_rect(int x, int y, int vect_x, int vect_y);
int		cub3d(t_stru *stru);
t_vect	create_vect(int x, int y);
int		check_map(t_stru *stru);
int		check_dep(t_stru *stru);
int		tab_to_matrix(t_stru *stru, char *map);
void	draw_line(t_stru *stru, t_vect pos1, t_vect pos2, t_color color);
t_tri	create_triangle(t_vect a, t_vect b, t_vect c);
void	draw_triangle(t_stru *stru, t_tri tri, t_color color);
void	fill_map(t_stru *stru, char *map, int i);
int		alloc_matrix(char *map, t_stru *stru);
void	departure_angle(t_stru *stru, char *map, int i);
int		error_parsing(void);
void	draw_circle(t_stru *stru, t_vect coord, t_color color, int radius);
int		absolute(int n);
float	calc_distance_vector(t_vect a, t_vect b);
void	save_image(void);
void	calcul_dist_screen(t_stru *stru);
void	calcul_map_size(t_stru *stru);
void	calcul_sprite_len(t_stru *stru);
void	calcul_res_rep(t_stru *stru);
double	d_pythagore(t_vect a, t_vect b);
char	*ft_itoa_base(long nb, char *base);

#endif
