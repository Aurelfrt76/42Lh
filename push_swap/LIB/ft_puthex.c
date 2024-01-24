/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:56:51 by afromont          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:49 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, unsigned long *index)
{
	if (n < 16)
		ft_putchar(LOWERCASE[n], index);
	if (n > 15)
	{
		ft_puthex(n / 16, index);
		ft_puthex(n % 16, index);
	}
}
