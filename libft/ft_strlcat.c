/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:44:12 by afromont          #+#    #+#             */
/*   Updated: 2023/10/27 09:46:39 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = ft_strlen (dest);
	j = ft_strlen(src);
	k = i;
	l = 0;
	if (count == 0)
		return (j);
	if (i < count - 1 && count > 0)
	{
		while (src[l] && i + l < count - 1)
		{
			dest[k] = src[l];
			k++;
			l++;
		}
		dest[k] = '\0';
	}
	if (i >= count)
		i = count;
	return (i + j);
}
