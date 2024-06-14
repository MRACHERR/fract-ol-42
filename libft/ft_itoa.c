/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:43:12 by acherraq          #+#    #+#             */
/*   Updated: 2023/12/05 19:47:07 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_l(long int n)
{
	long int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static long int	ft_abs(long int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*s;
	int		sign;

	l = ft_l(n);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	sign = 0;
	if (n >= 0)
		sign = 1;
	s[l] = '\0';
	l--;
	while (l >= 0)
	{
		s[l] = 48 + ft_abs(n % 10);
		n = n / 10;
		l--;
	}
	if (sign == 0)
		s[0] = '-';
	return (s);
}
