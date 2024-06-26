/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:04 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/26 18:40:42 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include "printf/ft_printf.h"
# include <limits.h>
# include <math.h>
# define ERROR_MSG "Usage: \n\t./fractol mandelbrot\n \
	./fractol julia [c_real] [c_imaginary]\n"

typedef struct s_fractal
{
	char	*name;
	int		width;
	int		height;
	void	*mlx;
	void	*window;
	int		color;
	double	c_re;
	double	c_im;
	double	zoom;
	double	move_x;
	double	move_y;
	int		max_iter;
	void	*image;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_fractal;
void		handle_errors(char *error_msg);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_valid_nb(char *str);
void		graphe_mandlebrot_init(t_fractal *fractal);
void		draw_mandelbrot(t_fractal *fractal);
void		arg_verify(int argc, char **argv);
char		*ft_tolow(char *str);
void		fractal_init(t_fractal *fractal, int argc, char **argv);
void		fractal_init(t_fractal *fractal, int argc, char **argv);
double		ft_atod(const char *str);
void		fractal_initialize(t_fractal *fractal, char *name);
void		draw_mandelbrot(t_fractal *fractal);
void		calcule_pixel_mandelbrot(t_fractal *fractal, int x, int y);
double		map(double unscated_num, double new_min, double new_max,
				double old_max);
void		draw_julia(t_fractal *fractal);
void		graphe_julia_init(t_fractal *fractal, double c_re, double c_im);
void		calcule_pixel_julia(t_fractal *fractal, int x, int y);
int			mouse_hook(int button, int x, int y, t_fractal *fractal);
int			close_window(t_fractal *fractal);
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
#endif