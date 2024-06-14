/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:12:04 by acherraq          #+#    #+#             */
/*   Updated: 2024/06/14 21:35:39 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>
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
}	t_fractal;

# define ERROR_message "Usage: \n\t./fractol mandelbrot\n \
	./fractol julia [c_real] [c_imaginary]\n"
void	handle_errors(char *error_msg);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_valid_nb(char *str);
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
#endif