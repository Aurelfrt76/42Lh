/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:47:51 by afromont          #+#    #+#             */
/*   Updated: 2023/11/09 14:42:16 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrunsigned(unsigned int n, unsigned long *index)
{
	int	mod;
	int	nb_div;

	if (n < 0)
	{
		ft_putchar('-', index);
		n -= n;
	}
	if (n > 9)
	{
		mod = n % 10;
		nb_div = n / 10;
		ft_putnbrunsigned(nb_div, index);
	}
	if (n > 9)
		ft_putchar(mod + '0', index);
	else
		ft_putchar(n + '0', index);
	return ;
}
