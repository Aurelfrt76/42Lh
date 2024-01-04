/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:01:53 by afromont          #+#    #+#             */
/*   Updated: 2023/10/17 14:43:08 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
/*
int main (void)
{
	printf("resultat test vrai %d\n", ft_isprint('Z'));
	printf("resultat test faux %d\n", ft_isprint('	'));
	return (0);
}
*/
