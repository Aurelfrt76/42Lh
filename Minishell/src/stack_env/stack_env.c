/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:11:38 by aliaudet          #+#    #+#             */
/*   Updated: 2024/03/28 16:17:29 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_stack	*add_var_env(t_stack *stack, char *name, char *value, t_garb *collec)
{
	t_stack	*buff;

	buff = stack;
	while (stack)
	{
		if (ft_strncmp(stack->name, name, ft_strlen(name) + 1) == 0)
		{
			stack->value = (char *)value;
			stack = buff;
			return (stack);
		}
		stack = stack->next;
	}
	stack = buff;
	stack = add_stack(stack, name, value, collec);
	if (stack->next)
		stack->next->prev = stack;
	return (stack);
}

t_stack	*first_stack_fill(t_stack *stack, char *env[], t_garb *collec)
{
	char	**var;
	int		i;
	int		j;

	i = 0;
	j = 0;
	var = allocate(sizeof(char *) * 2, collec);
	while (env[i])
	{
		while (env[i][j] != '=')
			j++;
		var[0] = ft_substr(env[i], 0, j, collec);
		var[1] = ft_substr(env[i], j + 1, ft_strlen(env[i]), collec);
		stack = add_stack(stack, var[0], var[1], collec);
		if (stack->next)
			stack->next->prev = stack;
		j = 0;
		i++;
	}
	return (stack);
}

t_stack	*loose_stack_pointer(t_stack *stack)
{
	if (!stack->prev)
	{
		stack->next->prev = NULL;
		return (stack->next);
	}
	else if (!stack->next)
	{
		stack->prev->next = NULL;
		return (NULL);
	}
	stack->prev->next = stack->next;
	stack->next->prev = stack->prev;
	return (stack);
}

t_stack	*rm_var_env(t_stack *stack, char *name, t_garb *gc)
{
	t_stack	*buff;

	(void)gc;
	buff = stack;
	while (stack)
	{
		if (ft_strncmp(name, stack->name, ft_strlen(name) + 1) == 0)
		{
			stack = loose_stack_pointer(stack);
			return (buff);
		}
		stack = stack->next;
	}
	return (buff);
}

char	**get_envarray(t_stack *stack, t_garb *gc)
{
	t_stack	*buff;
	t_count	c;
	char	**dst;

	c = (t_count){0, -1, 0};
	buff = stack;
	while (buff)
	{
		buff = buff->next;
		c.i++;
	}
	buff = stack;
	dst = allocate(sizeof(char *) * (c.i + 1), gc);
	c.j = c.i;
	while (--c.j >= 0)
	{
		dst[c.j] = ft_strjoin(buff->name, "=", gc);
		dst[c.j] = ft_strjoin(dst[c.j], buff->value, gc);
		buff = buff->next;
	}
	dst[c.i] = NULL;
	return (dst);
}
