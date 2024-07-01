/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:50:30 by aliaudet          #+#    #+#             */
/*   Updated: 2024/04/15 14:51:39 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	pipes_split(t_data *dt)
{
	t_count	c;

	c = (t_count){-1, 0, 0};
	while (dt->raw_cmd[++c.i])
		if (!in_quotes(dt->raw_cmd[c.i]) && dt->raw_cmd[c.i] == '|')
			c.k++;
	dt->cmd = allocate(sizeof(t_command) * (c.k + 1), &dt->gc);
	dt->cmd_num = c.k + 1;
	c.i = -1;
	c.k = 0;
	while (dt->raw_cmd[++c.i])
	{
		if (!in_quotes(dt->raw_cmd[c.i]) && dt->raw_cmd[c.i] == '|')
		{
			dt->cmd[c.k].data = dt;
			dt->cmd[c.k++].raw_cmd = ft_substr(dt->raw_cmd,
					c.j, c.i - c.j, &dt->gc);
			c.j = c.i;
			c.j++;
		}
	}
	dt->cmd[c.k].raw_cmd = ft_substr(dt->raw_cmd, c.j, c.i - c.j, &dt->gc);
	dt->cmd[c.k].data = dt;
	free(dt->raw_cmd);
	return (0);
}

static int	countw(const char *str)
{
	t_count	c;

	c = (t_count){-1, 0, 0};
	while (str[++c.i])
	{
		if (in_quotes(str[c.i]))
			continue ;
		if (str[c.i] != ' ' && c.j == 0)
		{
			c.j = 1;
			c.k++;
		}
		else if (str[c.i] == ' ')
			c.j = 0;
	}
	return (c.k);
}

static char	**quotes_splite(const char *str, int w_num, int t, t_garb *gc)
{
	t_count	c;
	char	**splite;

	c = (t_count){-1, 0, 0};
	splite = allocate(sizeof(char *) * (w_num + 1), gc);
	while (str[++c.i] && c.k < w_num)
	{
		if (in_quotes(str[c.i]))
			continue ;
		if ((str[c.i + 1] == ' ' || !str[c.i + 1]) && t == 0 && str[c.i] != ' ')
		{
			if (str[c.j] == ' ')
				splite[c.k++] = ft_substr(str, c.j + 1, (c.i) - c.j, gc);
			else
				splite[c.k++] = ft_substr(str, c.j, (c.i + 1) - c.j, gc);
			t = 1;
			c.j = c.i;
		}
		else if (str[c.i] == ' ')
		{
			t = 0;
			c.j++;
		}
	}
	return (splite[c.k] = NULL, splite);
}

static int	individual_command_parsing(t_command *cmds, int cmd_num, t_garb *gc)
{
	t_count	c;
	char	**words;

	c = (t_count){0, 1, -1};
	while (++c.k < cmd_num)
	{
		cmds[c.k].args_num = countw(cmds[c.k].raw_cmd) - 1;
		if (cmds[c.k].args_num < 0)
			return (EXITING);
		cmds[c.k].args = allocate(sizeof(char *) * cmds[c.k].args_num, gc);
		words = quotes_splite(cmds[c.k].raw_cmd, cmds[c.k].args_num + 1, 0, gc);
		cmds[c.k].cmd = ft_strdup(words[0], gc);
		while (words[c.j])
		{
			cmds[c.k].args[c.j - 1] = ft_strdup(words[c.j], gc);
			c.j++;
		}
		while (words[c.i])
			deallocate(words[c.i++], gc);
		deallocate(words, gc);
		c.i = 0;
		c.j = 1;
	}
	return (0);
}

int	parse_command(t_data *data)
{
	if (checking(data->raw_cmd) != 0)
		return (READING);
	if (pipes_split(data) != 0)
		return (READING);
	parse_var_env(data->cmd, data->cmd_num, &data->gc);
	if (parse_redir(data->cmd, data->cmd_num, &data->gc) != 0)
		return (READING);
	if (individual_command_parsing(data->cmd, data->cmd_num, &data->gc) != 0)
		return (READING);
	if (quote_cleaning(data->cmd, data->cmd_num) != 0)
		return (READING);
	return (EXECUTING);
}

// parsing_debug(data->cmd, data->cmd_num);
