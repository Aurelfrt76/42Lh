/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:10:29 by afromont          #+#    #+#             */
/*   Updated: 2023/12/29 12:18:15 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int pid, int l)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (l & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	send_argv(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	lenarg;

	i = 2;
	if (argc != 3 || argv[2][0] == '\0')
	{
		write(1, "Argument error (pid or message)\n", 32);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	lenarg = ft_strlen(argv[2]);
	if (lenarg != 0)
		send_len(pid, lenarg);
	if (argv[2])
	{
		while (*argv[2])
			send_argv(pid, *argv[2]++);
	}
	return (0);
}
