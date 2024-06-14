/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:09 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/14 22:51:44 by acherraq         ###   ########.fr       */
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


void	graphe_mandlebrot_init(t_fractal *fractal)
{
	fractal_initialize(fractal, fractal->name);
	fractal->zoom = 1;
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->max_iter = 100;
	fractal->color = 0x000CF7EA;
}
void	fractal_initialize(t_fractal *fractal, char *name)
{
	fractal->name = name;
	fractal->width = WINDOW_WIDTH;
	fractal->height = WINDOW_HEIGHT;
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		handle_errors("mlx faild!");
	fractal->window = mlx_new_windows(fractal->mlx, fractal->width, fractal->height, fractal->name)
	
	if (!fractal->window)
	{
		mlx_destroy_window(fractal->mlx, fractal->window);
		free(fractal->mlx);
		handle_errors("faild!");
	}
	
}