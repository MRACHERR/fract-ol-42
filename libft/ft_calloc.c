/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:20:44 by acherraq          #+#    #+#             */
/*   Updated: 2023/12/05 19:32:56 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*items;
	size_t	t;

	t = nitems * size;
	if (size != 0 && nitems != t / size)
		return (NULL);
	items = malloc(t);
	if (items == 0)
		return (NULL);
	ft_bzero(items, (nitems * size));
	return (items);
}
