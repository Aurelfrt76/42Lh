/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:31:49 by afromont          #+#    #+#             */
/*   Updated: 2023/10/18 11:19:16 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*result;

	result = (unsigned char *)src;
	while (*result != (unsigned char)c)
	{
		if (*result == '\0')
			return (NULL);
		result++;
	}
	return ((char *)result);
}
/*
int	main (void)
{
	printf("%s", ft_strchr("today", 'v'));
	return (0);
}
*/
