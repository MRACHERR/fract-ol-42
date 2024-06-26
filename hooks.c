#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		if (ft_strcmp(fractal->name, "julia") == 0)
			draw_julia(fractal);
		else
			draw_mandelbrot(fractal);
	}
	else if (button == 5)
	{
		fractal->zoom *= 0.9;
		if (ft_strcmp(fractal->name, "julia") == 0)
			draw_julia(fractal);
		else
			draw_mandelbrot(fractal);
	}
	return (0);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal);
		exit(1);
	}
	return (0);
}

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal);
	return (0);
	exit(1);
}