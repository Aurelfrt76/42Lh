/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:17:37 by aliaudet          #+#    #+#             */
/*   Updated: 2024/05/14 17:17:40 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	g_exit_status = 0;

void	update_sigaction(t_data *data, void (*h) (int, siginfo_t *, void *))
{
	data->sa.sa_sigaction = h;
	sigaction(SIGINT, &data->sa, NULL);
}

void	handler_exec(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		g_exit_status = 130;
	}
	else
		g_exit_status = -1;
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 130;
	}
	else
		g_exit_status = -1;
}

int	init_signal_handling(t_data *data)
{
	data->sa.sa_sigaction = &handler;
	data->sa.sa_flags = SA_SIGINFO;
	sigemptyset(&data->sa.sa_mask);
	sigaction(SIGINT, &data->sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}

int	init_minishell(t_data *data, char **env)
{
	data->env = env;
	data->var_env = NULL;
	data->gc = (t_garb){NULL, 0};
	data->var_env = first_stack_fill(data->var_env, env, &data->gc);
	data->shell_state = READING;
	data->cmd_num = 0;
	data->heredoc_stoped = 0;
	if (init_signal_handling(data) != 0)
		return (-1);
	return (0);
}
