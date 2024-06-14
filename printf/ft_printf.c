/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:44:32 by acherraq          #+#    #+#             */
/*   Updated: 2024/01/31 11:45:12 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ptr;

	if (write(1, "", 0))
		return (-1);
	va_start(ptr, s);
	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				break ;
			count += ft_format(ptr, s[++i]);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (count);
}
