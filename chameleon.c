/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chameleon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 21:30:53 by rbohmert          #+#    #+#             */
/*   Updated: 2016/06/11 07:59:06 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_chameleon(t_infos *i)
{
	i->x1 = -1.6;
	i->x2 = 1;
	i->y1 = -1;
	i->y2 = 1.3;
	i->c_r = 0.285;
	i->c_i = 0.01;
	i->zoom = (HEIGTH + WIDTH) / 5;
	i->i_max = 50;
	i->first = 1;
	i->motion = 0;
}

void			put_chameleon(t_infos *i)
{
	(i->first) ? 0 : init_chameleon(i);
	while (i->x < HEIGTH)
	{
		i->y = 0;
		while (i->y < WIDTH)
		{
			i->c_r = i->c_r;
			i->c_i = i->c_i;
			i->z_r = i->x / i->zoom + i->x1;
			i->z_i = i->y / i->zoom + i->y1;
			i->i = 0;
			while (i->z_r * i->z_r + i->z_i * i->z_i < 4 && i->i < i->i_max)
			{
				i->tmp = i->z_r;
				i->z_r = i->z_r * i->z_r - i->z_i * i->z_i + i->c_r;
				i->z_i = -2 * i->z_i * i->tmp + i->c_i;
				i->i++;
			}
			put_pixel(i);
			i->y++;
		}
		i->x++;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}
