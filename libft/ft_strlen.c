/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:16:42 by afromont          #+#    #+#             */
/*   Updated: 2023/10/25 13:07:43 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int main (void)
{
	printf("resultat test 1 %d\n", ft_strlen("anthony est con"));
	printf("resultat test 2 %d\n", ft_strlen("victoir aussi"));
	return (0);
}
*/
