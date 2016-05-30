#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define HEIGTH 500
# define WIDTH 500

typedef	struct	s_infos
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			s_line;
	int			endian;
	int			i_max;
	int			x;
	int			y;
	int			id;
	int			r;
	int			g;
	int			b;


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
	double		i;
}				t_infos;

void			error_usage(void);
void			parsing(t_infos *i, char **av, int ac);


#endif
