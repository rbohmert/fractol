#include "fractol.h"

void	put_pixel(t_infos *i)
{
	i->data[(i->s_line * i->y) + (4 * i->x) + 2] = (i->i * 255 / i->i_max) * i->b;
	i->data[(i->s_line * i->y) + (4 * i->x) + 1] = (i->i * 255 / i->i_max) * i->b * i->g;
	i->data[(i->s_line * i->y) + (4 * i->x)] = (i->i * 255 / i->i_max) * i->r * i->r * i->r;
}

void	error_usage(void)
{
	ft_putstr_fd("usage: ./fractol mandelbrot\n", 2);
	ft_putstr_fd("       ./fractol julia\n", 2);
	ft_putstr_fd("       ./fractol tricorn\n", 2);
	ft_putstr_fd("       ./fractol burn\n", 2);
	ft_putstr_fd("       ./fractol chameleon\n", 2);
	ft_putstr_fd("       ./fractol sword\n", 2);
	exit(2);
}

void	parsing(t_infos *i, char *av, int ac)
{
	if (ac != 2)
		error_usage();
	if (!ft_strcmp(av[1], "mandelbrot"))
		put_mandelbrot(i);
	else
		error_usage();
}


int		main (int ac, char **av)
{
	t_infos i;

	ft_bzero(&i, sizeof(t_infos));
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, HEIGTH, WIDTH, "Fractol");
	i.img = mlx_new_image(i.mlx, HEIGTH, WIDTH);
	i.data = mlx_get_data_addr(i.img, &(i.bpp), &(i.s_line), &(i.endian));
	parsing(&i, av[1], ac);
	mlx_mouse_hook(e->win_ptr, key_mouse, e);
	mlx_hook(e->win_ptr, 2, 3, key_hook, e);
	mlx_loop(i.mlx);
	return (0);
}

