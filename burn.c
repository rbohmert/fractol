/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 22:34:24 by rbohmert          #+#    #+#             */
/*   Updated: 2016/06/11 07:58:54 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				init_burning_ship(t_infos *i)
{
	i->x1 = -1.6;
	i->x2 = 1;
	i->y1 = -1;
	i->y2 = 1.3;
	i->zoom = (HEIGTH + WIDTH) / 5;
	i->i_max = 50;
	i->first = 1;
	i->motion = 0;
}

void				put_burning_ship(t_infos *i)
{
	(i->first) ? 0 : init_burning_ship(i);
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
				i->z_r = fabs(i->z_r * i->z_r - i->z_i * i->z_i + i->c_r);
				i->z_i = fabs(2 * i->z_i * i->tmp + i->c_i);
				i->i++;
			}
			put_pixel(i);
			i->y++;
		}
		i->x++;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}
