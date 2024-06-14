/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:19:57 by acherraq          #+#    #+#             */
/*   Updated: 2023/12/04 23:00:28 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_dst;
	unsigned char	*n_src;

	i = 0;
	n_dst = (unsigned char *)dst;
	n_src = (unsigned char *)src;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (n--)
			*n_dst++ = *n_src++;
	}
	else
	{
		while (i < n)
		{
			n_dst[n - i - 1] = n_src[n - i - 1];
			i++;
		}
	}
	return (dst);
}
