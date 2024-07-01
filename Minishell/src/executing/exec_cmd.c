/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:23:03 by afromont          #+#    #+#             */
/*   Updated: 2024/05/07 10:23:04 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

void	first_cmd(t_data *data, int pipe[2], int cmd_index)
{
	if (data->cmd[cmd_index].cmdin)
	{
		dup2(data->cmd[cmd_index].cmdin, 0);
		ft_close(1, data->cmd[cmd_index].cmdin);
	}
	if (data->cmd[cmd_index].cmdout)
	{
		dup2(data->cmd[cmd_index].cmdout, 1);
		ft_close(1, data->cmd[cmd_index].cmdout);
	}
	else
		if (pipe[1])
			dup2(pipe[1], 1);
	ft_close(2, pipe[0], pipe[1]);
	ftexecve(&data->cmd[cmd_index], &data->var_env, &data->gc);
}

void	middle_cmd(t_data *data, int pipe[2], int in_buff, int cmd_index)
{
	if (data->cmd[cmd_index].cmdout)
	{
		dup2(data->cmd[cmd_index].cmdout, 1);
		ft_close(1, data->cmd[cmd_index].cmdout);
	}
	else
		dup2(pipe[1], 1);
	if (data->cmd[cmd_index].cmdin)
	{
		dup2(data->cmd[cmd_index].cmdin, 0);
		ft_close(1, data->cmd[cmd_index].cmdin);
	}
	else
		dup2(in_buff, 0);
	ft_close(3, in_buff, pipe[0], pipe[1]);
	ftexecve(&data->cmd[cmd_index], &data->var_env, &data->gc);
}

void	last_cmd(t_data *data, int pipe[2], int in_buff, int cmd_index)
{
	if (data->cmd[cmd_index].cmdin)
	{
		dup2(data->cmd[cmd_index].cmdin, 0);
		ft_close(1, data->cmd[cmd_index].cmdin);
	}
	else
		dup2(in_buff, 0);
	if (data->cmd[cmd_index].cmdout)
	{
		dup2(data->cmd[cmd_index].cmdout, 1);
		ft_close(1, data->cmd[cmd_index].cmdout);
	}
	ft_close(3, in_buff, pipe[0], pipe[1]);
	ftexecve(&data->cmd[cmd_index], &data->var_env, &data->gc);
}

void	close_cmd_fds(t_command *cmds, int cmd_num)
{
	int	i;

	i = -1;
	while (++i < cmd_num)
		ft_close(2, cmds[i].cmdin, cmds[i].cmdout);
}

char	*get_var_env(t_stack *var_env, char *name)
{
	t_stack	*tmp;

	tmp = var_env;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->name, name, (ft_strlen(name) + 1)) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
