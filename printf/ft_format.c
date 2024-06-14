/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:37:23 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/06 19:45:43 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ptr, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(ptr, int));
	else if (format == 's')
		count += ft_putstr(va_arg(ptr, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(ptr, int));
	else if (format == 'u')
		count += ft_putunbr(va_arg(ptr, unsigned int));
	else if (format == 'X')
		count += ft_hexup(va_arg(ptr, int));
	else if (format == 'x')
		count += ft_hexlow(va_arg(ptr, unsigned int));
	else if (format == 'p')
		count += ft_ptr(va_arg(ptr, void *));
	else if (format == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &format, 1);
	return (count);
}
