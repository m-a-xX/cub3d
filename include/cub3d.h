/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 00:18:35 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/07 02:15:46 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
#define CUB3D_H

#include "../lib/mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define RED_VALUE 2
# define GREEN_VALUE 1
# define BLUE_VALUE 0

# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define UP 119# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362# define ESC 65307

typedef struct	s_stru
{
	char	**map;
	char	*pathNorth;
	char	*pathSouth;
	char	*pathEst;
	char	*pathWest;
	char	*pathSprite;
	int		mapHeight;
	int		mapWidth;
	int		screenHeight;
	int		screenWidth;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	cameraY;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	perpWallDist;
	int		lineHeight;
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

typedef struct  s_color
{
	int r;
	int g;
	int b;
}				t_color;

int		init_mlx(t_stru *stru);
t_stru	create_struct(void);
t_stru	*malloc_struct(void);
void	free_struct(t_stru *to_free);
t_color	create_color(int r, int b, int g);
void	raycast(t_stru *stru);
void	put_pixel(t_stru *stru, t_color color, int x, int y);


#endif