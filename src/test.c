/* #include "../include/cub3d.h"

void	p_value(int value, char *str)
{
	ft_putnbr_fd(value, 1);
	ft_putstr_fd(str, 1);
}

double	calcul_height(t_stru *stru, t_vect intersect)
{
	double dist;
	double height;

	intersect = mult_vects(intersect, stru->len_sprite);
	dist = d_pythagore(stru->pixel_pos, intersect);
	height = (double)64 / dist * stru->dist_screen;
	return (height);
}

t_vect	horizontal_intersecti(t_stru *stru, double angle)
{
	t_vect	tmp;
	t_vect	v;
	int		xa;
	int		ya;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	y1 = stru->pixel_pos.y;
	if (angle < 180 || (angle < -180 && angle > -360))
	{
		while (y1 % stru->len_sprite.y != 0)
			y1--;
		ya = -stru->len_sprite.y;
	}
	else
	{
		while (y1 % stru->len_sprite.y != 0)
			y1++;
		ya = stru->len_sprite.y;
	}
	x1 = stru->pixel_pos.x + (y1 - stru->pixel_pos.y) / tan_deg(angle);
	y2 = y1 + ya;
	x2 = x1 + ya / tan_deg(angle);
	xa = x2 - x1;
	v = create_vect(x1, x2);
	tmp = div_vects(v, stru->map_size);
	while (stru->map[tmp.x][tmp.y] && stru->map[tmp.x][tmp.y] != '1' && stru->map[tmp.x][tmp.y] != '2')
	{
		v.x += xa;
		v.y += ya;
		tmp = div_vects(v, stru->len_sprite);
		tmp.x = abs(tmp.x);
		tmp.y = abs(tmp.y);
	}
	ft_putnbr_fd(v.x, 1);
	ft_putstr_fd(" : x hor\n", 1);
	ft_putnbr_fd(v.y, 1);
	ft_putstr_fd(" : y hor\n", 1);
	return (v);
}

double	rad_to_deg(double rad)
{
	return (rad * 180 / M_PI);
}

int		main()
{
	t_stru *stru = malloc_struct();
	stru->pixel_pos = create_vect(50, 100);
	stru->map_size = create_vect(4, 4);
	stru->res = create_vect(200, 200);
	stru->len_sprite = create_vect(50, 50);
	char **map = malloc(sizeof(char *) * 5);
	map[4] = NULL;
	map[0] = ft_strdup("1111");
	map[1] = ft_strdup("1001");
	map[2] = ft_strdup("1N01");
	map[3] = ft_strdup("1111");
	stru->map = map;
	calcul_dist_screen(stru);
	//stru->orient.x = 0;
	//stru->orient.y = -(stru->len_sprite.y) / 6;
	stru->angle = 90;
	stru->orient = create_vect(10, 0);
	stru->pos.x = stru->pixel_pos.x / stru->len_sprite.x;
	stru->pos.y = stru->pixel_pos.y / stru->len_sprite.y;
	horizontal_intersecti(stru, 300);
	printf("%f", stru->dist_screen);
}
 */