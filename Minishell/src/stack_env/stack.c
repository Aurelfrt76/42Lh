/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:18:06 by aliaudet          #+#    #+#             */
/*   Updated: 2024/03/28 17:11:15 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_stack	*add_stack(t_stack *stack, char *name, char *value, t_garb *collec)
{
	t_stack	*new;

	new = allocate(sizeof(t_stack), collec);
	if (!new)
		return (NULL);
	new->name = ft_strdup(name, collec);
	new->value = ft_strdup(value, collec);
	new->next = stack;
	new->prev = NULL;
	return (new);
}

t_stack	*rm_stack(t_stack *stack, t_garb *collec)
{
	t_stack	*buff;

	buff = stack->next;
	deallocate(stack->name, collec);
	deallocate(stack->value, collec);
	deallocate(stack, collec);
	return (buff);
}
