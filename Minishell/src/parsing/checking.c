/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:31 by aliaudet          #+#    #+#             */
/*   Updated: 2024/04/11 14:21:15 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_quotes(const char *str)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while (str[i])
		status = in_quotes(str[i++]);
	in_quotes(0);
	return (status);
}

static int	check_pipe(const char *str)
{
	t_count	c;

	c = (t_count){.i = -1, .j = 0, .k = 0};
	while (str[++c.i])
	{
		c.j = in_quotes(str[c.i]);
		if ((ft_isprint(str[c.i]) && str[c.i] != ' ' && str[c.i] != '\t'
				&& str[c.i] != '|') || (str[c.i] == '|' && c.j))
			c.k = 1;
		if (str[c.i] == '|' && !c.j)
		{
			if (str[c.i + 1] == '<' || str[c.i + 1] == '>')
				return (1);
			if (!c.k)
				return (1);
			c.k = 0;
		}
	}
	in_quotes(0);
	if (!c.k)
		return (1);
	return (0);
}

static int	is_valid_redir(const char *str, int i)
{
	if (str[i + 1])
	{
		if (str[i + 1] == str[i])
		{
			if (str[i + 2] == '<' || str[i + 2] == '>')
				return (0);
		}
		else
		{
			if (str[i + 1] == '<' || str[i + 1] == '>' || str[i + 1] == '|')
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

static int	check_redir(const char *str, t_count c)
{
	while (str[++c.i])
	{
		if (in_quotes(str[c.i]))
			continue ;
		if ((str[c.i] == '<' || str[c.i] == '>') && !c.j)
		{
			if (!is_valid_redir(str, c.i))
				return (1);
			c.k = 0;
			c.j = 1;
		}
		if ((str[c.i] != '<' && str[c.i] != '>' && str[c.i] != '|') && c.j)
		{
			if (ft_isprint(str[c.i]) && str[c.i] != ' '
				&& str[c.i] != '\t')
			{
				c.k = 1;
				c.j = 0;
			}
		}
	}
	if (!c.k)
		return (1);
	return (0);
}

int	checking(const char *str)
{
	if (check_quotes(str))
		return (write(2, "invalide quote\n", 15), 1);
	if (check_pipe(str))
		return (1);
	if (check_redir(str, (t_count){-1, 0, 1}))
		return (write(2, "invalide redirection\n", 21), 1);
	return (0);
}
