/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:28:35 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/27 10:46:40 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		close_window(fractal);
	return (0);
}

int	close_window(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal);
	exit(1);
}
