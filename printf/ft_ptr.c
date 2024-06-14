/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:59:47 by acherraq          #+#    #+#             */
/*   Updated: 2024/03/30 16:03:32 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		counter++;
		n /= 16;
	}
	return (counter);
}

static void	ft_write_ptr(unsigned long long addr)
{
	char	*tab;

	tab = "0123456789abcdef";
	if (addr >= 16)
		ft_write_ptr(addr / 16);
	ft_putchar(tab[addr % 16]);
}

int	ft_ptr(void *addr)
{
	if (!addr)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	ft_write_ptr((unsigned long long)addr);
	return (2 + ft_count((unsigned long long)addr));
}
