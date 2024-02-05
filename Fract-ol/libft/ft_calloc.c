/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:40:12 by afromont          #+#    #+#             */
/*   Updated: 2023/11/07 16:42:02 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char		*dest;

	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
