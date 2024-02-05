/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:12:11 by afromont          #+#    #+#             */
/*   Updated: 2023/10/27 09:58:13 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr (set, s1[i -1]))
		i--;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (dest)
		ft_strlcpy(dest, s1, i + 1);
	return (dest);
}
