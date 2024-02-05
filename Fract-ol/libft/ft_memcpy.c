/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:35:33 by afromont          #+#    #+#             */
/*   Updated: 2023/10/17 15:10:37 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (n <= 0)
		return (d);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main (void)
{
	char	sr[] = "thebest";
	char	de[50];
	printf("source avant %s\n", sr);
	ft_memcpy (de, sr, 4);
	printf("source apres fonction %s\n", sr);
	printf("destination %s\n", de);
	return (0);
}
*/
