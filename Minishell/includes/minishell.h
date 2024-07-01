/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliaudet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:53:10 by aliaudet          #+#    #+#             */
/*   Updated: 2024/05/16 09:48:36 by aliaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../LIB/libft/libft.h"
# include "../LIB/GC/garbage_collector.h"

# define PROMPT		"# "
# define HEREDOC_PROMPT	"> "

# define T	512
# define A	1024
# define C	64

enum	e_shell_state
{
	READING,
	PARSING,
	EXECUTING,
	EXITING
};

enum	e_redir_type
{
	STDIN,
	HDC,
	STDOUT,
	STDAPP,
};

typedef struct s_count
{
	int	i;
	int	j;
	int	k;
}	t_count;

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	char			*name;
	char			*value;
}	t_stack;

typedef struct s_redir
{
	char	*file;
	int		type;
	int		ok;
}	t_redir;

typedef struct s_command
{
	struct s_data	*data;
	t_redir			*redirs;
	char			*raw_cmd;
	char			*cmd;
	char			**args;
	int				args_num;
	int				redir_num;
	int				cmdin;
	int				cmdout;
}	t_command;

typedef struct s_data
{
	struct sigaction	sa;
	t_command			*cmd;
	t_stack				*var_env;
	t_garb				gc;
	char				**env;
	char				*raw_cmd;
	int					shell_state;
	int					cmd_num;
	int					heredoc_stoped;
}	t_data;

// SIG
void	update_sigaction(t_data *data, void (*h) (int, siginfo_t *, void *));
void	handler_exec(int signum, siginfo_t *info, void *context);
void	handler(int signum, siginfo_t *info, void *context);

// ##############################
// #            ENV_VAR         #
// ##############################
t_stack	*add_var_env(t_stack *var, char *name, char *value, t_garb *collec);
t_stack	*rm_var_env(t_stack *var, char *name, t_garb *gc);
t_stack	*first_stack_fill(t_stack *stack, char *env[], t_garb *collec);
char	**get_envarray(t_stack *stack, t_garb *gc);

t_stack	*add_stack(t_stack *stack, char *name, char *value, t_garb *collec);
t_stack	*rm_stack(t_stack *stack, t_garb *collec);

// ##############################
// #		PARSING		#
// ##############################
void	parsing_debug(t_command *cmds, int cmd_num);
void	parse_var_env(t_command *cmds, int cmd_num, t_garb *gc);
char	*remove_quotes(char *str);
int		parse_command(t_data *data);
int		in_quotes(const char c);
int		is_partof_redirfile(const char c1, const char c2);
int		parse_redir(t_command *cmds, int cmd_num, t_garb *gc);
int		quote_cleaning(t_command *cmds, int cmd_num);
int		checking(const char *str);
int		count_redir(const char *str);

// ##############################
// #		EXECUTING	#
// ##############################

// ###########EXECUTING###########

void	ftexecve(t_command *cmd, t_stack **var_env, t_garb *gc);
int		exec_command(t_data *data);

// ###########EXEC_CMD############

void	first_cmd(t_data *data, int pipe[2], int cmd_index);
void	middle_cmd(t_data *data, int pipe[2], int in_buff, int cmd_index);
void	last_cmd(t_data *data, int pipe[2], int in_buff, int cmd_index);
void	close_cmd_fds(t_command *cmds, int cmd_num);

// ###########HEREDOC############

void	get_cmd_fds(t_command *cmd, t_garb *gc);

// ###########BUILT_IN###########

int		exec_exit(t_command *cmd);
int		exec_echo(t_command *cmd, t_count c);
int		exec_pwd(t_command *cmd);
int		exec_cd(t_command *cmd);
int		exec_export(t_command *cmd);
int		exec_unset(t_command *cmd);
int		exec_env(t_data *data);
int		exec_ctrl(t_data *data);

// ##############UTILS################

void	write_errno_execve(int erno, t_garb *gc);
char	**argsexecve(char *cmd, char **args, int arg_num, t_garb *gc);
char	*find_path(t_command *cmd, t_stack *var_env);
int		exit_cmderror(t_data *data, char *error);
int		exit_childerror(int error, t_garb *gc);
int		check_builtin(t_command *cmd);
int		is_correct_flag(const char *str);

// ###############INIT################

int		init_minishell(t_data *data, char **env);
char	*get_var_env(t_stack *var_env, char *name);

#endif
