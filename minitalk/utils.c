/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:11:01 by afromont          #+#    #+#             */
/*   Updated: 2023/12/28 15:57:12 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int n)
{
	int	mod;
	int	nb_div;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (n > 9)
	{
		mod = n % 10;
		nb_div = n / 10;
		ft_putnbr(nb_div);
	}
	if (n > 9)
		ft_putchar(mod + '0');
	else
		ft_putchar(n + '0');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *ptr)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (*ptr >= 48 && *ptr <= 57)
	{
		k = k * 10 + (*ptr - '0');
		ptr++;
	}
	return (k * i);
}
