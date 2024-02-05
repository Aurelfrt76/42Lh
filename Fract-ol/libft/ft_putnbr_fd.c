/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:35:34 by afromont          #+#    #+#             */
/*   Updated: 2023/10/25 09:18:54 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;
	int	nb_div;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		mod = n % 10;
		nb_div = n / 10;
		ft_putnbr_fd(nb_div, fd);
	}
	if (n > 9)
		ft_putchar_fd(mod + '0', fd);
	else
		ft_putchar_fd(n + '0', fd);
	return ;
}
