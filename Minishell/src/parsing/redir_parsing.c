/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:46:19 by aliaudet          #+#    #+#             */
/*   Updated: 2024/04/15 16:20:56 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	get_type(char c1, char c2)
{
	if (c1 == '<')
	{
		if (c2 == '<')
			return (HDC);
		return (STDIN);
	}
	else
	{
		if (c2 == '>')
			return (STDAPP);
		return (STDOUT);
	}
}

static char	*get_file_and_trim(t_count c, char **str, int new, t_garb *gc)
{
	char	*dst;

	c.k = ft_strlen((*str));
	if ((*str)[c.j] == ' ')
	{
		dst = ft_substr((*str), c.j + 1, (c.i) - c.j, gc);
		(*str) = ft_domstr((*str), new, c.i, gc);
	}
	else
	{
		dst = ft_substr((*str), c.j, (c.i + 1) - c.j, gc);
		(*str) = ft_domstr((*str), new, c.i + 1, gc);
	}
	dst = remove_quotes(dst);
	return (dst);
}

static char	*get_redirfile(char **str, int new_end, int start, t_garb *gc)
{
	t_count	c;
	int		trig;

	c = (t_count){start - 1, start, 0};
	trig = 0;
	while ((*str)[++c.i])
	{
		if (in_quotes((*str)[c.i]))
			continue ;
		if (!is_partof_redirfile((*str)[c.i], (*str)[c.i + 1]) && !trig)
			return (get_file_and_trim(c, str, new_end, gc));
		else if ((*str)[c.i] == ' ')
		{
			trig = 0;
			c.j++;
		}
	}
	return (NULL);
}

static void	get_redir(char **str, t_redir *redir, int redir_num, t_garb *gc)
{
	t_count	c;

	c = (t_count){-1, 0, 0};
	while ((*str)[++c.i] && c.k < redir_num)
	{
		if (in_quotes((*str)[c.i]))
			continue ;
		if ((*str)[c.i] == '<' || (*str)[c.i] == '>')
		{
			redir[c.k].type = get_type((*str)[c.i], (*str)[c.i + 1]);
			c.j = c.i;
			while ((*str)[c.i] && ((*str)[c.i] == '<' || (*str)[c.i] == '>'
					|| (*str)[c.i] == ' '))
				c.i++;
			if ((*str)[c.i])
				redir[c.k].file = get_redirfile(str, c.j, c.i, gc);
			c.k++;
			c.i = -1;
		}
	}
}

int	parse_redir(t_command *cmds, int cmd_num, t_garb *gc)
{
	t_count	c;

	c = (t_count){.k = -1};
	while (++c.k < cmd_num)
	{
		cmds[c.k].redir_num = count_redir(cmds[c.k].raw_cmd);
		cmds[c.k].redirs = allocate(sizeof(t_redir) * cmds[c.k].redir_num, gc);
		get_redir(&cmds[c.k].raw_cmd, cmds[c.k].redirs,
			cmds[c.k].redir_num, gc);
		cmds[c.k].cmdin = 0;
		cmds[c.k].cmdout = 0;
		get_cmd_fds(&cmds[c.k], gc);
	}
	if (cmds->data->heredoc_stoped)
		return (cmds->data->heredoc_stoped = 0, 1);
	return (0);
}
