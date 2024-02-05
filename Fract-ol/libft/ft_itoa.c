/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:47:33 by afromont          #+#    #+#             */
/*   Updated: 2023/10/27 17:16:24 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_rechlen(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while ((unsigned int)n != 0)
	{
		i++;
		n = (unsigned int)n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	len;
	size_t	i;

	i = 0;
	len = (ft_rechlen (n));
	dest = malloc(sizeof(char) * (len + 1));
	if (dest)
	{
		if (n < 0)
		{
			*dest = '-';
			n = -n;
			i++;
		}
		dest[len] = 0;
		while (i < len)
		{
			dest[len - 1] = '0' + ((unsigned int)n % 10);
			n = (unsigned int)n / 10;
			len--;
		}
	}
	return (dest);
}
