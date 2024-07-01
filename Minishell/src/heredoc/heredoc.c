/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:37:52 by aliaudet          #+#    #+#             */
/*   Updated: 2024/05/14 16:38:04 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

int	ft_open(const char *path, int flags, int mode)
{
	int	fd;

	fd = open(path, flags, mode);
	if (errno == ENOENT)
		g_exit_status = 1;
	return (fd);
}

static void	get_userinput(t_redir *redir, int fd, t_garb *gc)
{
	char	*usrin;

	usrin = NULL;
	while (ft_strncmp(redir->file, usrin, ft_strlen(redir->file) + 1))
	{
		write(2, "> ", 2);
		usrin = gnl(0, gc);
		if (ft_strncmp(redir->file, usrin, ft_strlen(redir->file) + 1) == 0)
			break ;
		if (!usrin)
			return ;
		write(fd, usrin, ft_strlen(usrin));
		write(fd, "\n", 1);
	}
}

static int	get_heredoc_fd(t_redir *redir, t_data *data, t_garb *gc)
{
	char	*tmpfile_name;
	int		fd;

	g_exit_status = 0;
	tmpfile_name = ft_strjoin("/tmp/TMP__MINISHELL__HEREDOC__",
			redir->file, gc);
	fd = ft_open(tmpfile_name, O_WRONLY | O_CREAT | O_APPEND
			| O_TRUNC, 0644);
	update_sigaction(data, &handler_exec);
	get_userinput(redir, fd, gc);
	if (g_exit_status == 130)
		data->heredoc_stoped = 1;
	update_sigaction(data, &handler);
	ft_close(1, fd);
	if (!data->heredoc_stoped)
		fd = open(tmpfile_name, O_RDONLY, 0644);
	return (fd);
}

void	get_cmd_fds(t_command *cmd, t_garb *gc)
{
	t_count	c;

	c = (t_count){.k = -1};
	while (++c.k < cmd->redir_num)
	{
		if (cmd->redirs[c.k].type == STDOUT || cmd->redirs[c.k].type == STDAPP)
		{
			ft_close(1, cmd->cmdout);
			if (cmd->redirs[c.k].type == STDAPP)
				cmd->cmdout = ft_open(cmd->redirs[c.k].file, 1 | C | A, 0644);
			else
				cmd->cmdout = ft_open(cmd->redirs[c.k].file, 1 | C | T, 0644);
			cmd->redirs[c.k].ok = cmd->cmdout;
		}
		else if (cmd->redirs[c.k].type == STDIN || cmd->redirs[c.k].type == HDC)
		{
			ft_close(1, cmd->cmdin);
			if (cmd->redirs[c.k].type == HDC)
				cmd->cmdin = get_heredoc_fd(&cmd->redirs[c.k], cmd->data, gc);
			else
				cmd->cmdin = ft_open(cmd->redirs[c.k].file, O_RDONLY, 0644);
			cmd->redirs[c.k].ok = cmd->cmdin;
		}
	}
}
