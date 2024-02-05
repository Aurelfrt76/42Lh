/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:55 by afromont          #+#    #+#             */
/*   Updated: 2023/10/23 13:36:38 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
		n--;
	}
	return (0);
}
/*
int 	main (void)
{
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1, "Hello", 6);
	memcpy(str2, "Helpo", 6);

	ret = ft_memcmp(str1, str2, 3);

	if(ret > 0)
		printf("str2 is less than str1");
	else if(ret < 0)
		printf("str1 is less than str2");
	else
		printf("str1 is equal to str2");
   
	return(0);
}
*/
