#include "fractol.h"

void	init_mandelbrot(t_infos *i)
{
	i->x1 = -1;//-3;
	i->x2 = 1;//2.5;
	i->y1 = -1;//-2;
	i->y2 = 1;//3;
	i->zoom = (HEIGTH + WIDTH) / 5;//259.37;
	i->i_max = 80;
	i->id = 1;
	i->r = 5;
	i->g = 5;
	i->b = 5;
	//i->motion = 0;
}

void	put_mandelbrot(t_infos *i)
{
	(i->id) ? 0 : init_mandelbrot(i);
	while (i->x < HEIGTH)
	{
		i->y = 0;
		while (i->y < WIDTH)
		{
			i->c_r = i->x / i->zoom + i->x1;
			i->c_i = i->y / i->zoom + i->y1;
			i->z_r = 0;
			i->z_i = 0;
			i->i = 0;
			while (i->z_r * i->z_r + i->z_i * i->z_i < 4 && i->i < i->i_max)
			{
				i->tmp = i->z_r;
				i->z_r = i->z_r * i->z_r - i->z_i * i->z_i + i->c_r;
				i->z_i = 2 * i->z_i * i->tmp + i->c_i;
				i->i++;
			}
			(i->i != i->i_max) ? put_pixel(i) : 0;
			i->y++;
		}
		i->x++;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}
