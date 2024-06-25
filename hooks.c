#include "fractol.h"
int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{

}

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal);
	exit (1);
}