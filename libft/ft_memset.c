/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:33:51 by afromont          #+#    #+#             */
/*   Updated: 2023/10/17 14:56:52 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int val, size_t i)
{
	char	*dest;
	size_t	j;

	dest = (char *)src;
	j = 0;
	while (j < i)
	{
		dest[j] = val;
		j++;
	}
	return (src);
}
/*
int	main (void)
{
	char	str[10];
	ft_memset(str, 'A', 5);
	printf("%s", str);
	return (0);
}
*/
