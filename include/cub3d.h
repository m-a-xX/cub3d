/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 00:18:35 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/25 01:16:36 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

#include "../lib/mlx/mlx.h"
#include "../lib/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define BUFFER_SIZE 10

# define RED_VALUE 2
# define GREEN_VALUE 1
# define BLUE_VALUE 0

# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define UP 119
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define ESC 65307

# define KEYPRESS_EVENT 2
# define KEYPRESS_MASK 1
# define KEYRELEASE_EVENT 3
# define KEYRELEASE_MASK 2

typedef struct  s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_stru
{
	char	**map;
	char	*path_north;
	char	*path_south;
	char	*path_est;
	char	*path_west;
	char	*path_sprite;
	t_color	rgb_floor;
	t_color	rgb_top;
	int		map_height;
	int		map_width;
	int		screen_height;
	int		screen_width;
	char	begin_dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	cameraY;
	double	raydir_x;
	double	raydir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	move_speed;
	double	rot_speed;
	int		map_x;
	int		map_y;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		drawStart;
	int		drawEnd;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*pixels;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_stru;

/* GNL */
int             get_next_line(int fd, char **line);
int             ft_search_nl(char *str);
char    *ft_strjoin_free(char *s1, char *s2, int c);
void    *ft_memset(void *s, int c, size_t n);
void    *ft_calloc(size_t nb, size_t size);
int             ft_len_line(const char *stock);
int             ft_loop(char **stock, int fd, char *buffer);
int             ft_atoi(const char *nb);

/* CUB3D */
int		init_mlx(t_stru *stru);
t_stru	create_struct(void);
t_stru	*malloc_struct(void);
void	free_struct(t_stru *to_free);
t_color	create_color(int r, int b, int g);
void	raycast(t_stru *stru);
void	put_pixel(t_stru *stru, t_color color, int x, int y);
int		loop_hook(t_stru *stru);
int		key_hook(int keyhook, t_stru *stru);
int		exit_hook(t_stru *stru);
char	*strjoin_free_nl(char *s1, char *s2);
int		check_stru(t_stru *stru);
int		analyse_line(char *line, t_stru *stru, int i);
int		alloc_matrix(char *map, t_stru *stru);
void	fill_map(t_stru *stru, char *map, int i, int x);
int		check_map(t_stru *stru);
int		parse_cub(int fd, t_stru *stru);
void	print_pos(t_stru *stru);
void	clear(t_stru *stru);
void	draw_line(t_stru *stru, int pos1_x, int pos1_y, int pos2_x, int pos2_y, t_color color);
void	print_struct(t_stru *stru);
void	print_ray(t_stru *stru);
void	draw_circle(t_stru *stru, int coord_x, int coord_y, int radius);
void	dda(t_stru *stru);
int		verify_move(char c);
void	vertical_move(int keyhook, t_stru *stru);
void	horizontal_move(int keyhook, t_stru *stru);
void	rotation_right(int keyhook, t_stru *stru);
void	rotation_left(int keyhook, t_stru *stru);

#endif