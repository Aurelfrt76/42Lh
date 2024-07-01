/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:20:13 by aliaudet          #+#    #+#             */
/*   Updated: 2024/05/14 17:20:15 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*remove_quotes(char *str)
{
	t_count	c;
	int		dst_index;

	c = (t_count){-1, 0, 0};
	dst_index = 0;
	while (str[++c.i])
	{
		c.j = in_quotes(str[c.i]);
		if (c.j && !c.k)
		{
			c.k = 1;
			continue ;
		}
		else if (!c.j && c.k)
		{
			c.k = 0;
			continue ;
		}
		str[dst_index] = str[c.i];
		dst_index++;
	}
	while (dst_index < c.i)
		str[dst_index++] = 0;
	return (str);
}

int	quote_cleaning(t_command *cmds, int cmd_num)
{
	t_count	c;

	c = (t_count){0, -1, -1};
	while (++c.k < cmd_num)
	{
		cmds[c.k].cmd = remove_quotes(cmds[c.k].cmd);
		while (++c.j < cmds[c.k].args_num)
			cmds[c.k].args[c.j] = remove_quotes(cmds[c.k].args[c.j]);
		c.j = -1;
	}
	return (0);
}
