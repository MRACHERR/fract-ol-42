/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:33:23 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/26 18:33:24 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcule_pixel_mandelbrot(t_fractal *fractal, int x, int y)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_im = 0;
	z_re = 0;
	i = 0;
	fractal->c_re = map(x, -2, 2, fractal->width) * fractal->zoom
		+ fractal->move_x;
	fractal->c_im = map(y, 2, -2, fractal->height) * fractal->zoom
		+ fractal->move_y;
	while (z_re * z_re + z_im * z_im < 4 && i < fractal->max_iter)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + fractal->c_re;
		z_im = 2 * z_im * tmp + fractal->c_im;
		i++;
	}
	if (i == fractal->max_iter)
		fractal->addr[y * fractal->width + x] = 0x00000000;
	else
		fractal->addr[y * fractal->width + x] = i * fractal->color;
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < fractal->height)
	{
		x = 0;
		while (x < fractal->width)
		{
			calcule_pixel_mandelbrot(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
}

void	graphe_mandlebrot_init(t_fractal *fractal)
{
	fractal_initialize(fractal, fractal->name);
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->max_iter = 100;
	fractal->color = 0x000C17EA;
	draw_mandelbrot(fractal);
}
