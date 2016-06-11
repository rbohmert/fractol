/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 18:25:02 by rbohmert          #+#    #+#             */
/*   Updated: 2016/06/11 08:08:57 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key, t_infos *i)
{
	(key == 53) ? exit(2) : 0;
	(key == 123) ? i->x1 += 5 / i->zoom : 0;
	(key == 124) ? i->x1 -= 5 / i->zoom : 0;
	(key == 125) ? i->y1 -= 5 / i->zoom : 0;
	(key == 126) ? i->y1 += 5 / i->zoom : 0;
	(key == 69) ? i->i_max++ : 0;
	(key == 78) ? i->i_max-- : 0;
	(key == 69) ? i->zoom *= 1.1 : 0;
	(key == 78) ? i->zoom /= 1.1 : 0;
	(key == 116) ? i->i_max += 5 : 0;
	if (key == 121)
		(i->i_max -= 5) == 0 ? i->i_max = 5 : 0;
	if (key == 256)
		i->motion = (!i->motion) ? 1 : 0;
	(key == 48) ? change(i) : 0;
	(key == 49) ? i->first = 0 : 0;
	parsing(i);
	return (1);
}

int		key_mouse(int key, int x, int y, t_infos *i)
{
	double x_real;
	double y_real;

	if (y > 0)
	{
		x_real = (x / i->zoom) + i->x1;
		y_real = (y / i->zoom) + i->y1;
		if (key == 4)
		{
			i->zoom *= 1.1;
			i->x1 = x_real - (x / i->zoom);
			i->y1 = y_real - (y / i->zoom);
			i->i_max += 1;
			parsing(i);
		}
		if (key == 5)
		{
			i->zoom /= 1.1;
			i->x1 = x_real - (x / i->zoom);
			i->y1 = y_real - (y / i->zoom);
			i->i_max -= 1;
			parsing(i);
		}
	}
	return (0);
}

int		get_r(int x)
{
	if (x < 255 || x >= 1275)
		return (255);
	if (x < 510)
		return (510 - x);
	if (x < 1020)
		return (0);
	if (x <= 1275)
		return (x - 1020);
	else
		return (255);
}

int		get_g(int x)
{
	if (x < 255)
		return (x);
	if (x < 765)
		return (255);
	if (x < 1020)
		return (1020 - x);
	if (x <= 1530)
		return (0);
	else
		return (255);
}

int		get_b(int x)
{
	if (x < 510)
		return (0);
	if (x < 765)
		return (x - 510);
	if (x < 1275)
		return (255);
	if (x < 1530)
		return (1530 - x);
	else
		return (255);
}
