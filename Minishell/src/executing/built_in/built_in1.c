/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:32:25 by afromont          #+#    #+#             */
/*   Updated: 2024/05/07 09:32:28 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

int	exec_unset(t_command *cmd)
{
	int	i;

	i = -1;
	if (cmd->args_num == 0)
		return (0);
	while (++i < cmd->args_num)
		cmd->data->var_env = rm_var_env(cmd->data->var_env, cmd->args[i],
				&cmd->data->gc);
	cmd->data->shell_state = READING;
	return (0);
}

int	exec_env(t_data *data)
{
	t_stack	*buff;

	buff = data->var_env;
	while (buff->next)
		buff = buff->next;
	while (buff)
	{
		printf("%s=%s\n", buff->name, buff->value);
		buff = buff->prev;
	}
	data->shell_state = READING;
	return (0);
}

int	check_error_export(char *str)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (++i < ft_strlen(str))
	{
		if (str[i] == '-')
			return (1);
		if (strncmp(str, "=", 2) == 0)
			return (1);
		if (str[0] >= '0' && str[0] <= '9')
			return (1);
		if (str[i] == '=')
			j = 1;
		if (i == (ft_strlen(str) - 1))
			break ;
	}
	if (j == 0)
		return (2);
	return (0);
}

int	exec_export(t_command *cmd)
{
	int		i;
	char	**var;

	i = -1;
	while (++i < cmd[0].args_num)
	{
		if (check_error_export(cmd[0].args[i]) != 0)
		{
			if (check_error_export(cmd[0].args[i]) == 1)
				write(2, "export: error syntax\n", 22);
			else
				return (0);
			return (1);
		}
		var = ft_split(cmd[0].args[i], '=', &cmd->data->gc);
		if (var[1] == NULL)
			cmd->data->var_env = add_var_env(cmd->data->var_env, var[0], "",
					&cmd->data->gc);
		else
			cmd->data->var_env = add_var_env(cmd->data->var_env, var[0],
					var[1], &cmd->data->gc);
	}
	cmd->data->shell_state = READING;
	return (0);
}

int	exec_exit(t_command *cmd)
{
	if (cmd->args_num)
		if (ft_atoi(cmd[0].args[0]) == 0)
			return (2);
	if (cmd[0].args_num > 1)
		return (1);
	else
	{
		printf("exit\n");
		cmd->data->shell_state = EXITING;
		if (cmd->args_num)
			return (ft_atoi(cmd[0].args[0]));
		return (0);
	}
}
