/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:09 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/27 14:42:15 by acherraq         ###   ########.fr       */
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

int	ft_valid_nb(char *s)
{
	char	*s_before_numberskip;

	skip_whitespace(&s);
	if (*s == '-' || *s == '+')
		s++;
	s_before_numberskip = s;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s == 0 && s > s_before_numberskip)
		return (1);
	if (*s != '.')
		return (0);
	s++;
	s_before_numberskip = s;
	while (*s >= '0' && *s <= '9')
		s++;
	if (s_before_numberskip == s)
		return (0);
	skip_whitespace(&s);
	return (*s == 0);
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
	if (str[i] == '-' || str[i] == '+')
		sign = 44 - str[i++];
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

void	fractal_initialize(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->width = WINDOW_WIDTH;
	fractal->height = WINDOW_HEIGHT;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		handle_errors("mlx faild!");
	fractal->window = mlx_new_window(fractal->mlx, fractal->width,
			fractal->height, fractal->name);
	if (!fractal->window)
		handle_errors_free("Failed to get image!", fractal);
	fractal->image = mlx_new_image(fractal->mlx, fractal->width,
			fractal->height);
	if (!fractal->image)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		handle_errors_free("Failed to get image!", fractal);
	}
	fractal->addr = (int *)mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->line_length, &fractal->endian);
	if (!fractal->addr)
	{
		mlx_destroy_image(fractal->mlx, fractal->image);
		mlx_destroy_window(fractal->mlx, fractal->window);
		handle_errors_free("Failed to get image address!", fractal);
	}
}
