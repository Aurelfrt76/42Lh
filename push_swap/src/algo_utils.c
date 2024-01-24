/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:22:29 by afromont          #+#    #+#             */
/*   Updated: 2024/01/23 11:22:31 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include "../LIB/ft_printf.h"

int	is_sorted(t_stack *st)
{
	while (st->next)
	{
		if (st->value > st->next->value)
			return (0);
		st = st->next;
	}
	return (1);
}

int	is_bigger_than_stack(int value, t_stack *st)
{
	while (st)
	{
		if (value < st->value)
			return (0);
		st = st->next;
	}
	return (1);
}

int	is_best_option(int va, int vb, t_stack *st)
{
	while (st)
	{
		if (st->value > vb && st->value < va)
			return (0);
		st = st->next;
	}
	return (1);
}

void	select_push(t_stack **sta, t_stack **stb, int num)
{
	int	dir;

	if ((*sta)->value == 0 || (*sta)->next->value == 0
		|| (*sta)->next->next->value == 0)
		dir = 0;
	else
		dir = 1;
	while (1)
	{
		if ((*sta)->value == num)
		{
			st_push(stb, sta, 'b');
			break ;
		}
		else
		{
			if (dir == 0)
				st_rotate(sta, 'a');
			else if (dir == 1)
				st_rev_rotate(sta, 'a');
		}
	}
}

int	stlen(t_stack *st, int i)
{
	if (!st)
		return (i);
	return (stlen(st->next, i + 1));
}
