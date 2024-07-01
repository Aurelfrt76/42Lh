/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:38:33 by aliaudet          #+#    #+#             */
/*   Updated: 2024/04/15 13:36:39 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

static void	reading(t_data *data)
{
	data->raw_cmd = readline(PROMPT);
	if (!data->raw_cmd)
	{
		data->shell_state = EXITING;
		return ;
	}
	add_history(data->raw_cmd);
	data->shell_state = PARSING;
}

int	main(int argc, char *argv[], char *env[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	if (init_minishell(&data, env) == 0)
	{
		while (42)
		{
			if (data.shell_state == READING)
				reading(&data);
			if (data.shell_state == PARSING)
				data.shell_state = parse_command(&data);
			if (data.shell_state == EXECUTING)
				data.shell_state = exec_command(&data);
			if (data.shell_state == EXITING)
				break ;
		}
	}
	rl_clear_history();
	clean_garbage(&data.gc);
	return (g_exit_status);
}
