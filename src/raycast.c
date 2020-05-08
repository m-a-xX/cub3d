/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 02:00:18 by mavileo           #+#    #+#             */
/*   Updated: 2020/05/08 18:27:06 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
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

void	dda_init(t_stru *stru)
{
	stru->deltaDistX = (stru->rayDirY == 0) ? 0 : ((stru->rayDirX == 0) ? 1 : fabs(1 / stru->rayDirX));
	stru->deltaDistY = (stru->rayDirX == 0) ? 0 : ((stru->rayDirY == 0) ? 1 : fabs(1 / stru->rayDirY));

	if (stru->rayDirX < 0)
		stru->sideDistX = (stru->posX - stru->mapX) * stru->deltaDistX;
	else
	{
		stru->stepX = 1;
		stru->sideDistX = (stru->mapX + 1.0 - stru->posX) * stru->deltaDistX;
	}
	if (stru->rayDirY < 0)
	{
		stru->stepY = -1;
		stru->sideDistY = (stru->posY - stru->mapY) * stru->deltaDistY;
	}
	else
	{
		stru->stepY = 1;
		stru->sideDistY = (stru->mapY + 1.0 - stru->posY) * stru->deltaDistY;
	}
}

double	d_pythagore(int aX, int bX, int aY, int bY)
{
	return (sqrt(pow((double)(bX - aX), 2) + pow((double)(bY - aY), 2)));
}

void	draw_circle(t_stru *stru, int coordX, int coordY, t_color color, int radius)
{
	int		actualX;
	int		actualY;
	int		target_x;
	int		target_y;

	target_x = coordX + radius;
	target_y = coordY + radius;
	actualX = coordX - radius;
	while (actualX < target_x)
	{
		actualY = coordY - radius;
		while (actualY < target_y)
		{
			if (d_pythagore(coordX, actualX, coordY, actualY) <= radius)
				put_pixel(stru, color, actualX, actualY);
			actualY++;
		}
		actualX++;
	}
}

void	draw_line(t_stru *stru, int pos1X, int pos1Y, int pos2X, int pos2Y, t_color color)
{
	int		dX;
	int		dY;
	int		sX;
	int		sY;
	int		err;
	int		e2;

	dX = abs(pos2X - pos1X);
	sX = pos1X < pos2X ? 1 : -1;
	dY = abs(pos2Y - pos1Y);
	sY = pos1Y < pos2Y ? 1 : -1; 
	err = (dX > dY ? dX : -dY) / 2;
	while (!(pos1X == pos2X && pos1Y == pos2Y))
	{
		put_pixel(stru, color, pos1X, pos1Y);
		e2 = err;
		if (e2 > -dX)
		{
			err -= dY;
			pos1X += sX;
		}
		if (e2 < dY)
		{
			err += dX;
			pos1Y += sY;
		}
	}
}

void	print_pos(t_stru *stru)
{
	int x = 5*24, y = 5*24;
	while (x >= 0)
	{
		y = 5*24;
		while (y >= 0)
		{
			if (worldMap[x/5][y/5] > 0)
				put_pixel(stru, create_color(255,255,255), x, y--);
			else
				put_pixel(stru, create_color(0,0,0), x, y--);
		}
		x--;
	}
	draw_circle(stru, stru->posX*5, stru->posY*5, create_color(255,255,255), 5);
}

void	dda(t_stru *stru)
{
	while (stru->hit == 0)
	{
		if (stru->sideDistX < stru->sideDistY)
		{
			stru->sideDistX += stru->deltaDistX;
			stru->mapX += stru->stepX;
			stru->side = 0;
		}
		else
		{
			stru->sideDistY += stru->deltaDistY;
			stru->mapY += stru->stepY;
			stru->side = 1;
		}
		if (worldMap[stru->mapX][stru->mapY] > 0)
			stru->hit = 1;
	}
}

void	calcul_height_column(t_stru *stru)
{
	if (stru->side == 0)
		stru->perpWallDist = (stru->mapX - stru->posX + (1 - stru->stepX) / 2) / stru->rayDirX;
	else
		stru->perpWallDist = (stru->mapY - stru->posY + (1 - stru->stepY) / 2) / stru->rayDirY;
	stru->lineHeight = (int)(stru->screenHeight / stru->perpWallDist);
	stru->drawStart = -stru->lineHeight / 2 + stru->screenHeight / 2;
	if(stru->drawStart < 0)
		stru->drawStart = 0;
	stru->drawEnd = stru->lineHeight / 2 + stru->screenHeight / 2;
	if(stru->drawEnd >= stru->screenHeight)
		stru->drawEnd = stru->screenHeight - 1;
}

void	draw_column(t_stru *stru, int x)
{
	t_color color;
	
	switch(worldMap[stru->mapX][stru->mapY])
	{
		case 1:	color = create_color(25, 65, 112);	break;
		case 2:	color = create_color(25, 0, 112);	break;
		case 3:	color = create_color(150, 54, 35);	 break;
		case 4:	color = create_color(2, 65, 200);	break;
		default: color = create_color(0, 65, 112); break;
	}
	if (stru->side == 1)
	{
		color.r = color.r / 2;
		color.g = color.g / 2;
		color.b = color.b / 2;
	}
	while (stru->drawStart <= stru->drawEnd)
		put_pixel(stru, color, x, stru->drawStart++);
}

void	raycast(t_stru *stru)
{
	int x;

	x = 0;
	stru->planeX = 0.66;
	stru->planeY = 0;
	int oldS = 0, S = 0;
	print_pos(stru);
	while (x < stru->screenWidth)
	{
		oldS = S;
		stru->cameraX = 2 * x / (double)(stru->screenWidth) - 1;
		stru->rayDirX = stru->dirX + stru->planeX * stru->cameraX;
		stru->rayDirY = stru->dirY + stru->planeY * stru->cameraX;
		stru->mapX = (int)(stru->posX);
		stru->mapY = (int)(stru->posY);
		stru->hit = 0;
		stru->stepX = -1;
		dda_init(stru);
		dda(stru);
		calcul_height_column(stru);
		draw_column(stru, x);
		S = stru->side;
		draw_line(stru, stru->posX*5, stru->posY*5, stru->posX*5 + (stru->rayDirX * 20), stru->posY*5 + (stru->rayDirY * 20), create_color(255,255,255));
		if (x == 200 || x == 400)
		{
			printf("x %d\nperpWallDist %f\nlineHeight %d\nrayDirX %f\nrayDirY %f\n\n", x, stru->perpWallDist, stru->lineHeight, stru->rayDirX, stru->rayDirY);
		}
		x++;
	}
}

void	clear(t_stru *stru)
{
	int x;
	int y;

	x = 0;
	while (x < stru->screenWidth)
	{
		y = 0;
		while (y < stru->screenHeight)
			put_pixel(stru, create_color(0,0,0), x, y++);
		x++;
	}
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
}

void	vertical_move(int keyhook, t_stru *stru)
{
	if (keyhook == UP)
	{
		if (worldMap[(int)(stru->posX + stru->dirX * stru->moveSpeed)][(int)(stru->posY)] == 0)
			stru->posX += stru->dirX * stru->moveSpeed;
		if (worldMap[(int)(stru->posX)][(int)(stru->posY + stru->dirY * stru->moveSpeed)] == 0)
			stru->posY += stru->dirY * stru->moveSpeed;
	}
	else if (keyhook == DOWN)
	{
		if (worldMap[(int)(stru->posX - stru->dirX * stru->moveSpeed)][(int)(stru->posY)] == 0)
			stru->posX -= stru->dirX * stru->moveSpeed;
		if (worldMap[(int)(stru->posX)][(int)(stru->posY - stru->dirY * stru->moveSpeed)] == 0)
			stru->posY -= stru->dirY * stru->moveSpeed;
	}
}

void	horizontal_move(int keyhook, t_stru *stru)
{
	if (keyhook == LEFT)
	{
		if (worldMap[(int)(stru->posX - stru->planeX  * stru->rotSpeed)][(int)(stru->posY)] == 0)
			stru->posX -= stru->planeX * stru->rotSpeed;
		if (worldMap[(int)(stru->posX)][(int)(stru->posY - stru->planeY * stru->rotSpeed)] == 0)
			stru->posY -= stru->planeY * stru->rotSpeed;
	}
	else if (keyhook == RIGHT)
	{
		if (worldMap[(int)(stru->posX + stru->planeX  * stru->rotSpeed)][(int)(stru->posY)] == 0)
			stru->posX += stru->planeX * stru->rotSpeed;
		if (worldMap[(int)(stru->posX)][(int)(stru->posY + stru->planeY * stru->rotSpeed)] == 0)
			stru->posY += stru->planeY * stru->rotSpeed;
	}
}

void	rotation(int keyhook, t_stru *stru)
{
	double oldDirX;
	double oldPlaneX;

	if (keyhook ==ARROW_LEFT )
	{
		oldDirX = stru->dirX;
		stru->dirX = stru->dirX * cos(-stru->rotSpeed) - stru->dirY * sin(-stru->rotSpeed);
		stru->dirY = oldDirX * sin(-stru->rotSpeed) + stru->dirY * cos(-stru->rotSpeed);
		oldPlaneX = stru->planeX;
		stru->planeX = stru->planeX * cos(-stru->rotSpeed) - stru->planeY * sin(-stru->rotSpeed);
		stru->planeY = oldPlaneX * sin(-stru->rotSpeed) + stru->planeY * cos(-stru->rotSpeed);
	}
	else if (keyhook == ARROW_RIGHT)
	{
		oldDirX = stru->dirX;
		stru->dirX = stru->dirX * cos(stru->rotSpeed) - stru->dirY * sin(stru->rotSpeed);
		stru->dirY = oldDirX * sin(stru->rotSpeed) + stru->dirY * cos(stru->rotSpeed);
		oldPlaneX = stru->planeX;
		stru->planeX = stru->planeX * cos(stru->rotSpeed) - stru->planeY * sin(stru->rotSpeed);
		stru->planeY = oldPlaneX * sin(stru->rotSpeed) + stru->planeY * cos(stru->rotSpeed);
	}
}

int		key_hook(int keyhook, t_stru *stru)
{
	printf("%d\n", keyhook);
	printf("%f %f\n", stru->posX, stru->posY);
	if (keyhook == ESC)
		exit_hook(stru);
	vertical_move(keyhook, stru);
	horizontal_move(keyhook, stru);
	rotation(keyhook, stru);
	clear(stru);
	raycast(stru);
	mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	return (0);	clear(stru);
}
