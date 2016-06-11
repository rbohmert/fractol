/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spierpinski.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:40:16 by rbohmert          #+#    #+#             */
/*   Updated: 2016/06/11 08:02:46 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_brain(t_infos *i)
{
	i->x1 = -1.6;
	i->x2 = 1;
	i->y1 = -1;
	i->y2 = 1.3;
	i->c_r = 0.6;
	i->c_i = 0.2;
	i->zoom = (HEIGTH + WIDTH) / 5;
	i->i_max = 50;
	i->first = 1;
}

void	put_brain(t_infos *i)
{
	(i->first) ? 0 : init_brain(i);
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
				i->tmp2 = i->z_i;
				i->z_r = i->tmp * i->tmp - i->tmp2 * i->tmp2 + i->c_r;
				i->z_i = 2 * fabs(i->tmp * i->tmp2) + i->c_i;
				i->i++;
			}
			put_pixel(i);
			i->y++;
		}
		i->x++;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}
