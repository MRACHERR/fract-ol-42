/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:09 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/26 15:00:25 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_errors(char *error_msg)
{
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_valid_nb(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i] || (str[i] == '.' && !str[i + 1]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[i++] == '.')
	{
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (0);
			i++;
		}
	}
	return (1);
}

double	ft_atod(const char *str)
{
	double	res;
	double	res2;
	double	sign;
	int		i;
	int		j;

	res = 0;
	res2 = 0;
	sign = 1;
	i = 0;
	j = 1;
	// if (str[i] == '-' || str[i] == '+')
	// 	sign = 44 - str[i++];
	if (str[i] == '-' || str[i] == '+')
	{
    	sign = (str[i] == '-') ? -1 : 1;
    	i++;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + str[i++] - '0';
	if (str[i++] == '.')
		while (str[i])
			res2 = res2 + (str[i++] - '0') / pow(10, j++);
	if (((res + res2) * sign) > INT_MAX)
		return (INT_MAX);
	if (((res + res2) * sign) < INT_MIN)
		return (INT_MIN);
	return ((res + res2) * sign);
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

void	graphe_julia_init(t_fractal *fractal, double c_re, double c_im)
{
	fractal_initialize(fractal, fractal->name);
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->max_iter = 100;
	fractal->color = 0x000C17EA;
	fractal->c_im = c_im;
	fractal->c_re = c_re;
	draw_julia(fractal);

}


void	fractal_initialize(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->width = WINDOW_WIDTH;
	fractal->height = WINDOW_HEIGHT;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		handle_errors("mlx faild!");
	fractal->window = mlx_new_window(fractal->mlx, fractal->width, fractal->height, fractal->name);	
	if (!fractal->window)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal->mlx);
		handle_errors("faild!");
	}
	fractal->image = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	if (!fractal->image)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		mlx_destroy_image(fractal->mlx, fractal->image);
		free(fractal->mlx);
		handle_errors("error image");
	}
	fractal->addr = (int *)mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	int x;
	int y;
	
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
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0 , 0);
	
}

void calcule_pixel_mandelbrot(t_fractal *fractal, int x, int y)
{
	double z_re;
	double z_im;
	double tmp;
	int i;

	z_im = 0;
	z_re = 0;
	i = 0;
	fractal->c_re = map(x, -2, 2, fractal->width) * fractal->zoom + fractal->move_x;
	fractal->c_im = map(y, 2, -2, fractal->height) * fractal->zoom + fractal->move_y;
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

double	map(double unscated_num, double new_min, double new_max, double old_max)
{
	double	old_min;
	
	old_min = 0;
	return ((new_max - new_min) * (unscated_num - old_min) / (old_max - old_min) + new_min);
	
}

char	*ft_tolow(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
