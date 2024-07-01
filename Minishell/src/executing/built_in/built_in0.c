/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:52:20 by aliaudet          #+#    #+#             */
/*   Updated: 2024/03/26 14:58:43 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

void	exec_echo_n(t_command *cmd, int i)
{
	while (i < cmd->args_num - 1)
		printf("%s ", cmd->args[i++]);
	printf("%s", cmd->args[i]);
}

int	exec_echo(t_command *cmd, t_count c)
{
	while (++c.k < cmd->redir_num)
		if (cmd->redirs[c.k].ok == -1)
			return (1);
	if (!cmd->args_num)
		return (printf("\n"), 0);
	while (++c.i < cmd->args_num)
	{
		if (is_correct_flag(cmd->args[c.i]))
			c.j = 1;
		else
			break ;
	}
	if (c.j)
		exec_echo_n(cmd, c.i);
	else
	{
		while (c.i < cmd->args_num - 1)
			printf("%s ", cmd->args[c.i++]);
		printf("%s\n", cmd->args[c.i]);
	}
	cmd->data->shell_state = READING;
	return (0);
}

int	exec_pwd(t_command *cmd)
{
	char	*pwd;
	int		path_max;

	path_max = 4096;
	pwd = allocate(path_max * sizeof(char), &cmd->data->gc);
	if (pwd == NULL)
	{
		perror("failed ft_calloc exec_pwd");
		return (1);
	}
	pwd = getcwd(pwd, path_max);
	if (pwd == NULL)
	{
		printf("pwd: %s\n", strerror(errno));
		return (1);
	}
	printf("%s\n", pwd);
	cmd->data->shell_state = READING;
	return (0);
}

void	updatepathpwd(t_command *cmd, char *prevpwd, char *pwd)
{
	add_var_env(cmd->data->var_env, "OLDPWD", prevpwd, &cmd->data->gc);
	add_var_env(cmd->data->var_env, "PWD", getcwd(pwd, 4096), &cmd->data->gc);
}

int	exec_cd(t_command *cmd)
{
	char	*prevpwd;
	char	*pwd;
	char	*path;

	prevpwd = allocate(4096 * sizeof(char), &cmd->data->gc);
	pwd = allocate(4096 * sizeof(char), &cmd->data->gc);
	if (prevpwd == NULL || pwd == NULL)
		return (1);
	if ((getcwd(prevpwd, 4096)) == NULL)
		return (1);
	if (cmd->args_num == 0)
		path = get_var_env(cmd->data->var_env, "HOME");
	else if ((ft_strncmp(cmd->args[0], "-", 2) == 0))
		path = get_var_env(cmd->data->var_env, "OLDPWD");
	else
		path = cmd->args[0];
	if (cmd->args_num > 1)
		return (1);
	if ((chdir(path)) == -1)
		return (1);
	else
		updatepathpwd(cmd, prevpwd, pwd);
	return (0);
}
