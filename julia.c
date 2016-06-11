/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 21:26:10 by rbohmert          #+#    #+#             */
/*   Updated: 2016/06/11 08:10:54 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_julia(t_infos *i)
{
	i->x1 = -1.6;
	i->x2 = 1;
	i->y1 = -1;
	i->y2 = 1.3;
	i->c_r = -0.64;
	i->c_i = -0.55;
	i->zoom = (HEIGTH + WIDTH) / 5;
	i->i_max = 50;
	i->first = 1;
	i->motion = 1;
}

void			put_julia(t_infos *i)
{
	(i->first) ? 0 : init_julia(i);
	while (i->x < HEIGTH)
	{
		i->y = 0;
		while (i->y < WIDTH)
		{
			i->z_r = i->x / i->zoom + i->x1;
			i->z_i = i->y / i->zoom + i->y1;
			i->i = 0;
			while (i->z_r * i->z_r + i->z_i * i->z_i < 4 && i->i < i->i_max)
			{
				i->tmp = i->z_r;
				i->z_r = i->z_r * i->z_r - i->z_i * i->z_i + i->c_r;
				i->z_i = 2 * i->z_i * i->tmp + i->c_i;
				i->i++;
			}
			put_pixel(i);
			i->y++;
		}
		i->x++;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}

int				julia_motion(int x, int y, t_infos *i)
{
	if (i->motion && x > 0 && x <= WIDTH && y > 0 && y <= HEIGTH)
	{
		i->c_r = (double)(x + 400 - WIDTH) / 300;
		i->c_i = (double)(y + 320 - HEIGTH) / 300;
		put_julia(i);
	}
	i->x = 0;
	i->y = 0;
	return (0);
}
