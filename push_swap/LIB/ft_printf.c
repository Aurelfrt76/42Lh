/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:50:44 by afromont          #+#    #+#             */
/*   Updated: 2023/11/09 15:16:31 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(va_list args, char *str, size_t *index)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), index);
	else if (*str == 's')
		ft_putstr(va_arg(args, char *), index);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr(va_arg(args, int), index);
	else if (*str == '%')
		ft_putpercent(index);
	else if (*str == 'u')
		ft_putnbrunsigned(va_arg(args, unsigned int), index);
	else if (*str == 'x')
		ft_puthex(va_arg(args, unsigned int), index);
	else if (*str == 'X')
		ft_puthexup(va_arg(args, unsigned int), index);
	else if (*str == 'p')
		ft_putptr(va_arg(args, unsigned long), index);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	index;

	index = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(args, (char *)str, &index);
		}
		else
			ft_putchar(*str, &index);
		str++;
	}
	va_end(args);
	return (index);
}
/*
int	main()
{
	printf("%u", -19);
	printf("%d", ft_printf("%u", -19));
	return (0);
}*/
