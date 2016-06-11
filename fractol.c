/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 21:26:15 by rbohmert          #+#    #+#             */
/*   Updated: 2016/06/11 08:14:05 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_infos *i)
{
	if (i->i == i->i_max)
	{
		i->data[(i->s_line * i->y) + (4 * i->x) + 2] = 0;
		i->data[(i->s_line * i->y) + (4 * i->x) + 1] = 0;
		i->data[(i->s_line * i->y) + (4 * i->x)] = 0;
	}
	else
	{
		i->data[(i->s_line * i->y) + (4 * i->x) + 2] = \
		get_r((1530 / i->i_max) * i->i);
		i->data[(i->s_line * i->y) + (4 * i->x) + 1] = \
		get_g((1530 / i->i_max) * i->i);
		i->data[(i->s_line * i->y) + (4 * i->x)] = \
		get_b((1530 / i->i_max) * i->i);
	}
}

void	error_usage(void)
{
	ft_putstr_fd("usage: ./fractol 1 = mandelbrot\n", 2);
	ft_putstr_fd("       ./fractol 2 = julia\n", 2);
	ft_putstr_fd("       ./fractol 3 = sword\n", 2);
	ft_putstr_fd("       ./fractol 4 = chameleon\n", 2);
	ft_putstr_fd("       ./fractol 5 = tricorn\n", 2);
	ft_putstr_fd("       ./fractol 6 = burning_ship\n", 2);
	ft_putstr_fd("       ./fractol 7 = lapin\n", 2);
	ft_putstr_fd("       ./fractol 8 = brain\n", 2);
	exit(2);
}

void	parsing(t_infos *i)
{
	i->x = 0;
	i->y = 0;
	if (i->num == 1)
		put_mandelbrot(i);
	else if (i->num == 2)
		put_julia(i);
	else if (i->num == 3)
		put_sword(i);
	else if (i->num == 4)
		put_chameleon(i);
	else if (i->num == 5)
		put_tricorn(i);
	else if (i->num == 6)
		put_burning_ship(i);
	else if (i->num == 7)
		put_lapin(i);
	else if (i->num == 8)
		put_brain(i);
	else
		error_usage();
}

int		main(int ac, char **av)
{
	t_infos i;

	if (ac != 2)
		error_usage();
	ft_bzero(&i, sizeof(t_infos));
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, HEIGTH, WIDTH, "Fractol");
	i.img = mlx_new_image(i.mlx, HEIGTH, WIDTH);
	i.data = mlx_get_data_addr(i.img, &(i.bpp), &(i.s_line), &(i.endian));
	i.num = ft_atoi(av[1]);
	parsing(&i);
	mlx_hook(i.win, 6, 1L << 6, julia_motion, &i);
	mlx_hook(i.win, 2, 3, key_hook, &i);
	mlx_mouse_hook(i.win, key_mouse, &i);
	mlx_loop(i.mlx);
	return (0);
}
