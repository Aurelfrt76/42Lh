/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:36:40 by afromont          #+#    #+#             */
/*   Updated: 2024/05/22 23:40:42 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_builtin(t_command *cmd)
{
	if (strncmp(cmd->cmd, "echo", 5) == 0
		|| strncmp(cmd->cmd, "pwd", 4) == 0
		|| strncmp(cmd->cmd, "cd", 3) == 0
		|| strncmp(cmd->cmd, "export", 7) == 0
		|| strncmp(cmd->cmd, "unset", 6) == 0
		|| strncmp(cmd->cmd, "env", 4) == 0
		|| strncmp(cmd->cmd, "exit", 5) == 0)
		return (1);
	else
		return (0);
}

char	*pathjoin(t_stack *tmp, char *path, char **path_split, t_command *cmd)
{
	int	i;

	i = -1;
	path = ft_strdup(tmp->value, &cmd->data->gc);
	path_split = ft_split(path, ':', &cmd->data->gc);
	while (path_split[++i])
	{
		path = ft_strjoin(path_split[i], "/", &cmd->data->gc);
		path = ft_strjoin(path, cmd->cmd, &cmd->data->gc);
		if (access(path, F_OK) == 0)
			return (path);
	}
	return (path);
}

char	*find_path(t_command *cmd, t_stack *var_env)
{
	t_stack	*tmp;
	char	*path;
	char	**path_split;

	tmp = var_env;
	path = NULL;
	path_split = NULL;
	while (tmp != NULL)
	{
		if (cmd->cmd[0] == '.' || cmd->cmd[0] == '/')
		{
			if (access(cmd->cmd, F_OK) == 0)
				return (cmd->cmd);
			else
				return (NULL);
		}
		if (ft_strncmp(tmp->name, "PATH", 5) == 0)
			path = pathjoin(tmp, path, path_split, cmd);
		tmp = tmp->next;
	}
	return (path);
}

int	is_correct_flag(const char *str)
{
	int	i;

	i = -1;
	if (ft_strlen(str) >= 2)
	{
		if (str[0] == '-' && str[1] == 'n')
		{
			while (str[++i])
				if (str[i] == '-' && i != 0)
					return (0);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

char	**argsexecve(char *cmd, char **args, int arg_num, t_garb *gc)
{
	char	**dest;
	int		i;

	i = 0;
	dest = allocate(sizeof(char *) * (arg_num + 2), gc);
	dest[i] = cmd;
	while (++i < arg_num + 1)
		dest[i] = args[i - 1];
	dest[i] = NULL;
	return (dest);
}
