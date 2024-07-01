/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:39:42 by aliaudet          #+#    #+#             */
/*   Updated: 2024/05/22 23:40:07 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exit_cmderror(t_data *data, char *error)
{
	perror(error);
	return (data->shell_state = READING);
}

int	exit_childerror(int error, t_garb *gc)
{
	rl_clear_history();
	clean_garbage(gc);
	exit(error);
}

void	write_errno_execve(int erno, t_garb *gc)
{
	if (erno == EACCES)
	{
		write(2, " is a directory\n", 16);
		exit_childerror(126, gc);
	}
	else
	{
		write(2, " command not found\n", 19);
		exit_childerror(127, gc);
	}
}
