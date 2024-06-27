/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:00 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/27 10:47:45 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	arg_verify(argc, argv);
	fractal = (t_fractal *)malloc(sizeof(t_fractal));
	if (!fractal)
		handle_errors("malloc error\n");
	fractal->name = ft_tolow(argv[1]);
	fractal_init(fractal, argc, argv);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0, close_window, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}

void	fractal_init(t_fractal *fractal, int argc, char **argv)
{
	if (!ft_strcmp(fractal->name, "mandelbrot") && argc == 2)
		graphe_mandlebrot_init(fractal);
	else if (!ft_strcmp(fractal->name, "julia") && argc == 4
		&& ft_valid_nb(argv[2]) && ft_valid_nb(argv[3]))
	{
		if (ft_atod(argv[2]) > INT_MAX || ft_atod(argv[3]) > INT_MAX
			|| ft_atod(argv[2]) < INT_MIN || ft_atod(argv[3]) < INT_MIN)
		{
			free(fractal);
			handle_errors("invalid number \n");
		}
		graphe_julia_init(fractal, ft_atod(argv[2]), ft_atod(argv[3]));
	}
	else
	{
		free(fractal);
		handle_errors(ERROR_MSG);
	}
}

void	arg_verify(int argc, char **argv)
{
	(void)**argv;
	if (argc != 2 && argc != 4)
		handle_errors(ERROR_MSG);
}
