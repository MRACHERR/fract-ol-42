/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamrachi <hamrachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:07:43 by acherraq          #+#    #+#             */
/*   Updated: 2024/05/25 17:20:18 by hamrachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	long	nbr;
	long	sign;
	size_t	i;
	long	temp;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((str[i] != '\0') && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		temp = nbr;
		nbr = (nbr * 10) + (str[i] - '0');
		if (temp != nbr / 10)
			return (2147483649);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (2147483649);
		i++;
	}
	return (sign * nbr);
}
