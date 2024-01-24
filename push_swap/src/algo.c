/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:22:19 by afromont          #+#    #+#             */
/*   Updated: 2024/01/23 11:22:21 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include "../LIB/ft_printf.h"

void	two_args(t_stack **st)
{
	if (is_sorted((*st)))
		return ;
	else
		st_swap(st, 'a');
}

void	three_args(t_stack **st)
{
	if (is_sorted((*st)))
		return ;
	else if ((*st)->value > (*st)->next->value
		&& (*st)->value < (*st)->next->next->value)
		st_swap(st, 'a');
	else if ((*st)->value > (*st)->next->value
		&& (*st)->next->value > (*st)->next->next->value)
	{
		st_swap(st, 'a');
		st_rev_rotate(st, 'a');
	}
	else if ((*st)->value > (*st)->next->value
		&& (*st)->value > (*st)->next->next->value
		&& (*st)->next->value < (*st)->next->next->value)
		st_rotate(st, 'a');
	else if ((*st)->value < (*st)->next->value
		&& (*st)->value < (*st)->next->next->value)
	{
		st_swap(st, 'a');
		st_rotate(st, 'a');
	}
	else if ((*st)->value < (*st)->next->value
		&& (*st)->value > (*st)->next->next->value)
		st_rev_rotate(st, 'a');
}

void	four_args(t_stack **sta, t_stack **stb)
{
	select_push(sta, stb, 0);
	three_args(sta);
	st_push(sta, stb, 'a');
}

void	five_args(t_stack **sta, t_stack **stb)
{
	select_push(sta, stb, 0);
	select_push(sta, stb, 1);
	three_args(sta);
	st_push(sta, stb, 'a');
	st_push(sta, stb, 'a');
}

void	radx(t_stack **sta, t_stack **stb)
{
	t_count	c;
	int		num_bits;
	int		st_size;

	c = (t_count){0, 0};
	st_size = 0;
	num_bits = 0;
	st_size = stlen((*sta), st_size);
	while (((st_size - 1) >> num_bits) != 0)
		num_bits++;
	while (c.i < num_bits)
	{
		while (c.j < st_size)
		{
			if ((((*sta)->value >> c.i) & 1) == 1)
				st_rotate(sta, 'a');
			else
				st_push(stb, sta, 'b');
			c.j++;
		}
		while (!is_empty_stack((*stb)))
			st_push(sta, stb, 'a');
		c.j = 0;
		c.i++;
	}
}
