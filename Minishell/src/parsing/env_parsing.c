/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:05:40 by aliaudet          #+#    #+#             */
/*   Updated: 2024/04/11 15:37:27 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

static char	*get_var_name(char *str, t_garb *gc)
{
	t_count	c;
	char	*buff;

	c = (t_count){0, 0, 0};
	while (!ft_isalpha(str[c.i]) && str[c.i] != '_')
		c.i++;
	c.j = c.i;
	while ((ft_isalpha(str[c.j]) || str[c.j] == '_') && str[c.j])
		c.j++;
	buff = ft_substr(str, c.i, c.j - c.i, gc);
	return (buff);
}

static char	*ft_getenv(const char *name, t_stack *env, t_garb *gc)
{
	t_stack	*buff;

	buff = env;
	while (buff)
	{
		if (ft_strncmp(buff->name, name, ft_strlen(buff->name) + 1) == 0)
			return (ft_strdup(buff->value, gc));
		buff = buff->next;
	}
	return ("");
}

static char	*replace_to_value(char *cmd, const char *value, int sp, t_garb *gc)
{
	t_count	c;
	char	*buff;

	c = (t_count){ft_strlen(cmd), sp + 1, ft_strlen(value)};
	while ((ft_isalpha(cmd[c.j]) || cmd[c.j] == '_'
			|| cmd[c.j] == '?' || cmd[c.j] == '\\'
			|| cmd[c.j] == '/') && cmd[c.j])
	{
		c.j++;
		if (cmd[c.j] == '?')
		{
			c.j++;
			break ;
		}
	}
	buff = allocate(sizeof(char) * ((c.i + c.k) - (c.j - sp)) + 1, gc);
	c.i = -1;
	c.k = 0;
	while (cmd[++c.i] && c.i < sp)
		buff[c.i] = cmd[c.i];
	while (value[c.k])
		buff[c.i++] = value[c.k++];
	while (cmd[c.j])
		buff[c.i++] = cmd[c.j++];
	return (buff[c.i] = '\0', buff);
}

static int	choose_result(t_command *cmds, t_count c, t_garb *gc)
{
	char	*vname;
	char	*venv;

	if (cmds[c.k].raw_cmd[c.i + 1] == '?')
		cmds[c.k].raw_cmd = replace_to_value(cmds[c.k].raw_cmd,
				ft_itoa(g_exit_status, gc), c.i, gc);
	else if (cmds[c.k].raw_cmd[c.i + 1] == '$')
		cmds[c.k].raw_cmd = ft_domstr(cmds[c.k].raw_cmd, c.i, c.i + 2, gc);
	else if (cmds[c.k].raw_cmd[c.i + 1] == ' ' || cmds[c.k].raw_cmd[c.i + 1]
		== '\t' || !cmds[c.k].raw_cmd[c.i + 1])
		return (c.i + 1);
	else if (ft_isprint(cmds[c.k].raw_cmd[c.i + 1])
		&& cmds[c.k].raw_cmd[c.i + 1] != ' '
		&& cmds[c.k].raw_cmd[c.i + 1] != '\t')
	{
		vname = get_var_name(cmds[c.k].raw_cmd + c.i, gc);
		venv = ft_getenv(vname, cmds[c.k].data->var_env, gc);
		if (!venv)
			cmds[c.k].raw_cmd = replace_to_value(cmds[c.k].raw_cmd,
					"", c.i, gc);
		else
			cmds[c.k].raw_cmd = replace_to_value(cmds[c.k].raw_cmd,
					venv, c.i, gc);
	}
	return (c.i);
}

void	parse_var_env(t_command *cmds, int cmd_num, t_garb *gc)
{
	t_count	c;

	c = (t_count){-1, 0, -1};
	while (++c.k < cmd_num)
	{
		while (cmds[c.k].raw_cmd[++c.i])
		{
			if (in_quotes(cmds[c.k].raw_cmd[c.i]) != 1
				&& cmds[c.k].raw_cmd[c.i] == '$')
			{
				c.i = choose_result(cmds, c, gc);
				c.i--;
			}
		}
		c.i = -1;
	}
}
