/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:55 by afromont          #+#    #+#             */
/*   Updated: 2023/11/09 14:09:00 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s, unsigned long *index)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*index += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, index);
		s++;
	}
}
