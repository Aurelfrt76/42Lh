/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:49:55 by afromont          #+#    #+#             */
/*   Updated: 2023/11/09 09:58:06 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexup(unsigned int n, unsigned long *index)
{
	if (n < 16)
		ft_putchar(UPPERCASE[n], index);
	if (n > 15)
	{
		ft_puthexup(n / 16, index);
		ft_puthexup(n % 16, index);
	}
}
