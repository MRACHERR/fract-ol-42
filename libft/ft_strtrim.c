/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acherraq <acherraq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:21:26 by acherraq          #+#    #+#             */
/*   Updated: 2023/12/04 22:46:04 by acherraq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begining(const char *str, const char *s)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(str);
	while (i < l)
	{
		if (ft_strchr(s, str[i]) == 0)
		{
			break ;
		}
		i++;
	}
	return (i);
}

static int	ft_ending(const char *str, const char *s)
{
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(str);
	while (i < l)
	{
		if (ft_strchr(s, str[l - i - 1]) == 0)
		{
			break ;
		}
		i++;
	}
	return (l - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		finish;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_begining(s1, set);
	finish = ft_ending(s1, set);
	if (finish <= start)
		return (ft_strdup(""));
	ptr = (char *)malloc((finish - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + start, finish - start + 1);
	return (ptr);
}
