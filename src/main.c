/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/05/07 00:20:26 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct s_stru
{
  void  *mlx_ptr;
  void  *win_ptr;
  void  *img_ptr;
  char  *pixels;
  int     bpp;
  int     sizeline;
  int     endian;
}             t_stru;

typedef struct  s_color
{
		int r;
		int g;
		int b;
}                               t_color;

int		init_mlx(t_stru *stru)
{
	stru->mlx_ptr = mlx_init();
	stru->win_ptr = mlx_new_window(stru->mlx_ptr, screenWidth,
	screenHeight, "cub3d");
	stru->img_ptr = mlx_new_image(stru->mlx_ptr, screenWidth, screenHeight);
	stru->pixels = mlx_get_data_addr(stru->img_ptr, &(stru->bpp),
	&(stru->sizeline), &(stru->endian));
	return (0);
}

t_color create_color(int r, int b, int g)
{
		t_color color;

		color.r = r;
		color.g = g;
		color.b = b;
		return (color);
}

void	put_pixel(t_stru *stru, t_color color, int x, int y)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= screenWidth || y < 0 || y >= screenHeight)
		return ;
	pixel_index = x + (y * screenWidth);
	rel_pixel_index = pixel_index * 4;
	stru->pixels[rel_pixel_index + RED_VALUE] = color.r;
	stru->pixels[rel_pixel_index + GREEN_VALUE] = color.g;
	stru->pixels[rel_pixel_index + BLUE_VALUE] = color.b;
}

void raycast(t_stru *stru)
{
  double posX = 22, posY = 12;  //x and y start position
  double dirX = -1, dirY = 0; //initial direction vector
  double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
	for(int x = 0; x < screenWidth; x++)
	{
	  //calculate ray position and direction
	  double cameraX = 2 * x / (double)(screenWidth) - 1; //x-coordinate in camera space
	  double rayDirX = dirX + planeX * cameraX;
	  double rayDirY = dirY + planeY * cameraX;

	  //which box of the map we're in
	  int mapX = (int)(posX);
	  int mapY = (int)(posY);

	  //length of ray from current position to next x or y-side
	  double sideDistX;
	  double sideDistY;

	  // Alternative code for deltaDist in case division through zero is not supported
	  double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
	  double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
	  double perpWallDist;

	  //what direction to step in x or y-direction (either +1 or -1)
	  int stepX;
	  int stepY;

	  int hit = 0; //was there a wall hit?
	  int side; //was a NS or a EW wall hit?
	  //calculate step and initial sideDist
	  if (rayDirX < 0)
	  {
		stepX = -1;
		sideDistX = (posX - mapX) * deltaDistX;
	  }
	  else
	  {
		stepX = 1;
		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	  }
	  if (rayDirY < 0)
	  {
		stepY = -1;
		sideDistY = (posY - mapY) * deltaDistY;
	  }
	  else
	  {
		stepY = 1;
		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	  }
	  //perform DDA
	  while (hit == 0)
	  {
		//jump to next map square, OR in x-direction, OR in y-direction
		if (sideDistX < sideDistY)
		{
		  sideDistX += deltaDistX;
		  mapX += stepX;
		  side = 0;
		}
		else
		{
		  sideDistY += deltaDistY;
		  mapY += stepY;
		  side = 1;
		}
		//Check if ray has hit a wall
		if (worldMap[mapX][mapY] > 0) hit = 1;
	  }
	  //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
	  if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
	  else           perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
	  //Calculate height of line to draw on screen
	  int lineHeight = (int)(screenHeight / perpWallDist);

	  //calculate lowest and highest pixel to fill in current stripe
	  int drawStart = -lineHeight / 2 + screenHeight / 2;
	  if(drawStart < 0)drawStart = 0;
	  int drawEnd = lineHeight / 2 + screenHeight / 2;
	  if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;


	  //choose wall color
	  t_color color;
	  switch(worldMap[mapX][mapY])
	  {
		case 1:  color = create_color(25, 65, 112);  break; //red
		case 2:  color = create_color(25, 0, 112);  break; //green
		case 3:  color = create_color(150, 54, 35);   break; //blue
		case 4:  color = create_color(2, 65, 200);  break; //white
		default: color = create_color(0, 65, 112); break; //yellow
	  }

	  //give x and y sides different brightness
	  if (side == 1)
	  {
		color.r = color.r / 2;
		color.g = color.g / 2;
		color.b = color.b / 2;
	  }

	  //draw the pixels of the stripe as a vertical line
	  while (drawStart <= drawEnd)
	  {
		put_pixel(stru, color, x, drawStart++);
	  }
	  mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	}
}

int             cub3d(t_stru *stru)
{
		init_mlx(stru);
		raycast(stru);
		//mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
		//mlx_loop_hook(stru->mlx_ptr, loop_hook, stru);
		mlx_loop(stru->mlx_ptr);
		return (0);
}

int main()
{
	t_stru *stru = malloc(sizeof(t_stru));
	cub3d(stru);
}