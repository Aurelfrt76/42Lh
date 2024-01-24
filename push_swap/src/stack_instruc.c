/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:29:52 by afromont          #+#    #+#             */
/*   Updated: 2024/01/23 11:29:57 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include "../LIB/ft_printf.h"

void	st_swap(t_stack **st, char stp)
{
	int	buff;

	if (is_empty_stack((*st)) || (*st)->next == NULL)
		return ;
	buff = (*st)->value;
	(*st)->value = (*st)->next->value;
	(*st)->next->value = buff;
	ft_printf("s%c\n", stp);
}

void	st_push(t_stack **std, t_stack **sts, char stp)
{
	t_stack	*buff;

	if (is_empty_stack((*sts)))
		return ;
	(*std) = push_stack((*std), (*sts)->value);
	buff = (*sts)->next;
	free((*sts));
	(*sts) = buff;
	ft_printf("p%c\n", stp);
}

void	st_rotate(t_stack **st, char stp)
{
	t_stack	*buffpos;
	int		buff;

	if (is_empty_stack((*st)))
		return ;
	buffpos = (*st)->next;
	buff = (*st)->value;
	free((*st));
	(*st) = buffpos;
	while ((*st)->next)
		(*st) = (*st)->next;
	(*st)->next = push_stack((*st)->next, buff);
	(*st)->next->next = NULL;
	(*st) = buffpos;
	ft_printf("r%c\n", stp);
}

void	st_rev_rotate(t_stack **st, char stp)
{
	t_stack	*buffpos;
	int		buff;

	if (is_empty_stack((*st)))
		return ;
	buffpos = (*st);
	while ((*st)->next->next)
		(*st) = (*st)->next;
	buff = (*st)->next->value;
	free((*st)->next);
	(*st)->next = NULL;
	(*st) = buffpos;
	(*st) = push_stack((*st), buff);
	ft_printf("rr%c\n", stp);
}
