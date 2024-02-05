/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:50:58 by afromont          #+#    #+#             */
/*   Updated: 2023/10/17 15:05:45 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}
/*
int	main (void)
{
	char	str[50] = "testete seesfs";
	printf("avant %s \n", str);
	bzero(str, 5);
	printf("attendu %s \n", str);
	ft_bzero(str, 5);
	printf("apres %s", str);
	return (0);
}
*/	
