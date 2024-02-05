/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:25:16 by afromont          #+#    #+#             */
/*   Updated: 2023/10/23 10:28:16 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (*src != '\0')
	{
		i++;
		src++;
	}
	while ((unsigned char)*src != (unsigned char)c)
	{
		src--;
		if (i < 0)
			return (0);
		i--;
	}
	return ((char *)src);
}
/*
int     main (void)
{
        printf("%s", ft_strrchr("papa", '\0'));
        return (0);
}
*/
