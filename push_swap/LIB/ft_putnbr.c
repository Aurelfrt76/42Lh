/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:35:34 by afromont          #+#    #+#             */
/*   Updated: 2023/11/07 11:18:31 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, unsigned long *index)
{
	int	mod;
	int	nb_div;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		*index += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', index);
		n = -n;
	}
	if (n > 9)
	{
		mod = n % 10;
		nb_div = n / 10;
		ft_putnbr(nb_div, index);
	}
	if (n > 9)
		ft_putchar(mod + '0', index);
	else
		ft_putchar(n + '0', index);
	return ;
}
