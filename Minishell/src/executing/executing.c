/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:35:17 by afromont          #+#    #+#             */
/*   Updated: 2024/05/07 09:35:22 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

static int	exec_builtin(t_command *cmd)
{
	if (ft_strncmp(cmd->cmd, "echo", 5) == 0)
		return (exec_echo(cmd, (t_count){-1, 0, -1}));
	else if (ft_strncmp(cmd->cmd, "pwd", 4) == 0)
		return (exec_pwd(cmd));
	else if (ft_strncmp(cmd->cmd, "cd", 3) == 0)
		return (exec_cd(cmd));
	else if (ft_strncmp(cmd->cmd, "export", 7) == 0)
		return (exec_export(cmd));
	else if (ft_strncmp(cmd->cmd, "unset", 6) == 0)
		return (exec_unset(cmd));
	else if (ft_strncmp(cmd->cmd, "env", 4) == 0)
		return (exec_env(cmd->data));
	else if (ft_strncmp(cmd->cmd, "exit", 5) == 0)
		return (exec_exit(cmd));
	return (2);
}

void	ftexecve(t_command *cmd, t_stack **var_env, t_garb *gc)
{
	char	**tmp;
	int		i;

	i = -1;
	while (++i < cmd->redir_num)
	{
		if (cmd->redirs[i].ok == -1)
			exit_childerror(1, gc);
	}
	tmp = argsexecve(cmd->cmd, cmd->args, cmd->args_num, gc);
	if (cmd->cmdin == -1 || cmd->cmdout == -1)
		exit_childerror(EXIT_FAILURE, gc);
	if (check_builtin(cmd) == 1)
	{
		g_exit_status = exec_builtin(cmd);
		exit_childerror(g_exit_status, gc);
	}
	else if (execve(find_path(cmd, *var_env), tmp,
			get_envarray(*var_env, gc)) == -1)
		write_errno_execve(errno, gc);
}

static void	wait_for_childs(int i, pid_t *childs, int cmd_num)
{
	int	status;

	status = 0;
	while (++i < cmd_num)
	{
		waitpid(childs[i], &status, 0);
		g_exit_status = WEXITSTATUS(status);
	}
}

static int	exec_command1(t_data *data, int *pipes, int indx, int in_buff)
{
	pid_t	*childs;

	childs = allocate(sizeof(pid_t) * data->cmd_num, &data->gc);
	while (++indx < data->cmd_num)
	{
		ft_close(1, pipes[0]);
		if (indx < data->cmd_num - 1)
			if (pipe(pipes) == -1)
				return (EXITING);
		childs[indx] = fork();
		if (childs[indx] == -1)
			return (EXITING);
		if (indx == 0 && childs[indx] == 0)
			first_cmd(data, pipes, indx);
		else if (indx <= data->cmd_num - 2 && childs[indx] == 0)
			middle_cmd(data, pipes, in_buff, indx);
		else if (indx == data->cmd_num - 1 && childs[indx] == 0)
			last_cmd(data, pipes, in_buff, indx);
		ft_close(1, in_buff);
		in_buff = dup(pipes[0]);
		ft_close(1, pipes[1]);
	}
	ft_close(1, in_buff);
	wait_for_childs(-1, childs, data->cmd_num);
	return (0);
}

int	exec_command(t_data *data)
{
	int		pipes[2];
	int		in_buff;

	in_buff = 0;
	pipes[0] = 0;
	pipes[1] = 0;
	update_sigaction(data, &handler_exec);
	if (!data->cmd[0].cmd)
		return (EXITING);
	if (data->cmd_num == 1 && check_builtin(&data->cmd[0])
		&& !data->cmd[0].cmdin && !data->cmd[0].cmdout)
	{
		g_exit_status = exec_builtin(&data->cmd[0]);
		if (ft_strncmp(data->cmd[0].cmd, "exit", 5) == 0)
			return (EXITING);
		return (READING);
	}
	if (exec_command1(data, pipes, -1, in_buff) != 0)
		return (EXITING);
	close_cmd_fds(data->cmd, data->cmd_num);
	ft_close(3, in_buff, pipes[1], pipes[0]);
	update_sigaction(data, &handler);
	return (READING);
}
