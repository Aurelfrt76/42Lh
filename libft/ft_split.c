/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:20:43 by afromont          #+#    #+#             */
/*   Updated: 2023/11/06 12:34:43 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlong(const char *src, char c)
{
	size_t	i;

	i = 0;
	while (*src)
	{
		if (*src != c)
		{
			++i;
			while (*src && (*src != c))
				++src;
		}
		else
			++src;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**destfin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	destfin = malloc((ft_strlong(s, c) + 1) * sizeof(char *));
	if (!destfin)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c && ++j)
				++s;
			destfin[i++] = ft_substr(s - j, 0, j);
		}
		else
			++s;
	}
	destfin[i] = 0;
	return (destfin);
}
