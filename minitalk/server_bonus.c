/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:01:43 by afromont          #+#    #+#             */
/*   Updated: 2023/12/29 12:13:29 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_stat_serv = 0;

int	lenstr(int signal)
{
	static int	bit = 0;
	static int	i = 0;
	int			j;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 32)
	{
		g_stat_serv = 1;
		j = i;
		bit = 0;
		i = 0;
		return (j);
	}
	else
		j = 0;
	return (j);
}

void	ftput_signal(int signal, int size, siginfo_t *info)
{
	static int	bit = 0;
	static int	i = 0;
	static char	*str = NULL;

	if (!str)
		str = malloc(size * sizeof(char));
	if (signal == SIGUSR1)
		str[i] |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		i++;
		if (i == size)
		{
			str[i] = '\0';
			ft_putstr(str);
			ft_putchar('\n');
			str = NULL;
			i = 0;
			free(str);
			g_stat_serv = 0;
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
	}
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	len = 0;

	(void)context;
	if (g_stat_serv == 0)
		len = lenstr(signal);
	else if (g_stat_serv == 1)
		ftput_signal(signal, len, info);
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
	}
	return (0);
}
