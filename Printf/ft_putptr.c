/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:00:26 by afromont          #+#    #+#             */
/*   Updated: 2023/11/09 14:46:37 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long n, unsigned long *index)
{
	if (!n)
		ft_putstr("(nil)", index);
	else
	{
		ft_putstr("0x", index);
		ft_puthex(n, index);
	}
}
