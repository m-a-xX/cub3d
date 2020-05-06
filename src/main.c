/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:12:15 by user42            #+#    #+#             */
/*   Updated: 2020/05/07 01:07:57 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[24][24]=
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

void	put_pixel(t_stru *stru, t_color color, int x, int y)
{
	int pixel_index;
	int rel_pixel_index;

	if (x < 0 || x >= stru->screenWidth || y < 0 || y >= stru->screenHeight)
		return ;
	pixel_index = x + (y * stru->screenWidth);
	rel_pixel_index = pixel_index * 4;
	stru->pixels[rel_pixel_index + RED_VALUE] = color.r;
	stru->pixels[rel_pixel_index + GREEN_VALUE] = color.g;
	stru->pixels[rel_pixel_index + BLUE_VALUE] = color.b;
}

void raycast(t_stru *stru)
{

	stru->planeX = 0;
	stru->planeY = 0.66; //the 2d raycaster version of camera plane
	for(int x = 0; x < stru->screenWidth; x++)
	{
		//calculate ray position and direction
		stru->cameraX = 2 * x / (double)(stru->screenWidth) - 1; //x-coordinate in camera space
		stru->rayDirX = stru->dirX + stru->planeX * stru->cameraX;
		stru->rayDirY = stru->dirY + stru->planeY * stru->cameraX;

		//which box of the map we're in
		stru->mapX = (int)(stru->posX);
		stru->mapY = (int)(stru->posY);

		// Alternative code for deltaDist in case division through zero is not supported
		stru->deltaDistX = (stru->rayDirY == 0) ? 0 : ((stru->rayDirX == 0) ? 1 : fabs(1 / stru->rayDirX));
		stru->deltaDistY = (stru->rayDirX == 0) ? 0 : ((stru->rayDirY == 0) ? 1 : fabs(1 / stru->rayDirY));

		stru->hit = 0; //was there a wall hit?
		//calculate step and initial sideDist
		if (stru->rayDirX < 0)
		{
		stru->stepX = -1;
		stru->sideDistX = (stru->posX - stru->mapX) * stru->deltaDistX;
		}
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
		//perform DDA
		while (stru->hit == 0)
		{
		//jump to next map square, OR in x-direction, OR in y-direction
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
		//Check if ray has hit a wall
		if (worldMap[stru->mapX][stru->mapY] > 0) stru->hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (stru->side == 0) stru->perpWallDist = (stru->mapX - stru->posX + (1 - stru->stepX) / 2) / stru->rayDirX;
		else					 stru->perpWallDist = (stru->mapY - stru->posY + (1 - stru->stepY) / 2) / stru->rayDirY;
		//Calculate height of line to draw on screen
		stru->lineHeight = (int)(stru->screenHeight / stru->perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		stru->drawStart = -stru->lineHeight / 2 + stru->screenHeight / 2;
		if(stru->drawStart < 0)stru->drawStart = 0;
		stru->drawEnd = stru->lineHeight / 2 + stru->screenHeight / 2;
		if(stru->drawEnd >= stru->screenHeight)stru->drawEnd = stru->screenHeight - 1;


		//choose wall color
		t_color color;
		switch(worldMap[stru->mapX][stru->mapY])
		{
		case 1:	color = create_color(25, 65, 112);	break; //red
		case 2:	color = create_color(25, 0, 112);	break; //green
		case 3:	color = create_color(150, 54, 35);	 break; //blue
		case 4:	color = create_color(2, 65, 200);	break; //white
		default: color = create_color(0, 65, 112); break; //yellow
		}

		//give x and y sides different brightness
		if (stru->side == 1)
		{
		color.r = color.r / 2;
		color.g = color.g / 2;
		color.b = color.b / 2;
		}

		//draw the pixels of the stripe as a vertical line
		while (stru->drawStart <= stru->drawEnd)
		{
		put_pixel(stru, color, x, stru->drawStart++);
		}
		mlx_put_image_to_window(stru->mlx_ptr, stru->win_ptr, stru->img_ptr, 0, 0);
	}
}

int             cub3d(t_stru *stru)
{
	stru->posX = 22;
	stru->posY = 12;  //x and y start position

	stru->screenHeight = 400;
	stru->screenWidth = 600;

	stru->mapHeight = 24;
	stru->mapWidth = 24;

	stru->dirX = -1;
	stru->dirY = 0; //initial direction vector
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