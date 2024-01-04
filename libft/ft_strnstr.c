/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:07:56 by afromont          #+#    #+#             */
/*   Updated: 2023/10/23 13:25:40 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!s1 || !s2) && len == 0)
		return (NULL);
	if (!s2[0])
		return ((char *)s1);
	while (*s1 != '\0' && len >= i)
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0' && s1[i + j]
			== s2[j] && (i + j) < len)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&(s1[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s", ft_strnstr("t tod is bad", "tod", 10));
	return (0);
}
*/
