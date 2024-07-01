/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 05:43:47 by aliaudet          #+#    #+#             */
/*   Updated: 2024/04/09 16:48:10 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	count_redir(const char *str)
{
	t_count	c;

	c = (t_count){-1, 0, 0};
	while (str[++c.i])
	{
		if (in_quotes(str[c.i]))
			continue ;
		if ((str[c.i] == '<' || str[c.i] == '>') && c.j == 0)
		{
			c.k++;
			c.j = 1;
		}
		if (str[c.i] != '<' && str[c.i] != '>')
			c.j = 0;
	}
	return (c.k);
}

int	is_partof_redirfile(const char c1, const char c2)
{
	if ((c2 == ' ' || !c2 || c2 == '<' || c2 == '>') && c1 != ' ')
		return (0);
	return (1);
}

int	in_quotes(const char c)
{
	static int	in_quotes = 0;
	int			new_state;

	new_state = 0;
	if (!c)
		return (in_quotes = 0);
	if (c == '\'')
		new_state = 1;
	if (c == '\"')
		new_state = 2;
	if (!in_quotes)
		return (in_quotes = new_state);
	if (new_state != in_quotes)
		return (in_quotes);
	return (in_quotes = 0);
}

void	parsing_debug(t_command *cmds, int cmd_num)
{
	t_count	c;

	c = (t_count){0, 0, 0};
	printf("%sThere is %d command(s)\n", C_CYAN, cmd_num);
	while (c.k < cmd_num)
	{
		printf("%s==================================================%s\n",
			C_DEFAULT, C_CYAN);
		printf("\tCommand %d is '%s%s%s' and has %d arguments:\n",
			c.k + 1, C_RED, cmds[c.k].cmd, C_CYAN, cmds[c.k].args_num);
		while (c.j < cmds[c.k].args_num)
			printf("\t\t- '%s%s%s'\n",
				C_RED, cmds[c.k].args[c.j++], C_CYAN);
		printf("\tCommand %d has %d redirections:\n",
			c.k + 1, cmds[c.k].redir_num);
		c.j = -1;
		while (++c.j < cmds[c.k].redir_num)
			printf("\t\t- type: '%s%d%s' in: '%s%s%s' is '%s%d%s'%s\n", C_RED,
				cmds[c.k].redirs[c.j].type, C_CYAN, C_RED,
				cmds[c.k].redirs[c.j].file, C_CYAN, C_RED,
				cmds[c.k].redirs[c.j].ok,
				C_CYAN, C_DEFAULT);
		c.j = 0;
		c.k++;
	}
}
