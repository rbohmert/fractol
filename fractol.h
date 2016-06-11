/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 08:14:36 by rbohmert          #+#    #+#             */
/*   Updated: 2016/06/11 08:14:37 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>

# define HEIGTH 500
# define WIDTH 500

typedef	struct	s_infos
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			num;
	int			bpp;
	int			s_line;
	int			endian;
	int			i_max;
	int			x;
	int			y;
	int			first;
	int			motion;

	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	double		tmp2;
	double		i;
}				t_infos;

void			error_usage(void);
void			parsing(t_infos *i);
void			put_pixel(t_infos *i);

void			init_mandelbrot(t_infos *i);
void			put_mandelbrot(t_infos *i);
void			change(t_infos *i);

void			init_julia(t_infos *i);
void			put_julia(t_infos *i);
int				julia_motion(int x, int y, t_infos *i);

void			init_sword(t_infos *i);
void			put_sword(t_infos *i);

void			init_chameleon(t_infos *i);
void			put_chameleon(t_infos *i);

void			init_tricorn(t_infos *i);
void			put_tricorn(t_infos *i);

void			init_burning_ship(t_infos *i);
void			put_burning_ship(t_infos *i);

void			init_lapin(t_infos *i);
void			put_lapin(t_infos *i);

void			init_brain(t_infos *i);
void			put_brain(t_infos *i);

int				key_hook(int key, t_infos *i);
int				key_mouse(int key, int x, int y, t_infos *i);
int				get_r(int x);
int				get_g(int x);
int				get_b(int x);
#endif
