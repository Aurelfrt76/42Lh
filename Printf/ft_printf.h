/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:55:14 by afromont          #+#    #+#             */
/*   Updated: 2023/11/09 15:11:29 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define UPPERCASE "0123456789ABCDEF"
# define LOWERCASE "0123456789abcdef" 

void	ft_putchar(char c, unsigned long *index);

void	ft_putnbr(int n, unsigned long *index);

void	ft_putstr(const char *s, unsigned long *index);

void	ft_putpercent(unsigned long *index);

void	ft_putnbrunsigned(unsigned int n, unsigned long *index);

void	ft_puthex(unsigned long n, unsigned long *index);

void	ft_puthexup(unsigned int n, unsigned long *index);

void	ft_putptr(unsigned long long n, unsigned long *index);

int		ft_printf(const char *str, ...);

#endif
