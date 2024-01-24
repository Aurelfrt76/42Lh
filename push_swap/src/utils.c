/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:20:44 by afromont          #+#    #+#             */
/*   Updated: 2024/01/23 11:20:49 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include "../LIB/ft_printf.h"

long	ft_atoi(const char *str)
{
	long	res;
	int		neg_count;
	int		pos_count;

	neg_count = 0;
	pos_count = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg_count++;
		if (*str == '+')
			pos_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if ((neg_count + pos_count) > 1)
		return (0);
	if (neg_count == 1)
		res = -res;
	return (res);
}

/* ********** error management ************* */

void	exit_with_error(const char *err_msg)
{
	ft_printf("%s", err_msg);
	exit(1);
}

void	ftgesterror(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			exit_with_error("Error\n");
		if (i > 1 && ft_atoi(argv[i - 1]) == ft_atoi(argv[i]))
			exit_with_error("Error\n");
		if ((ft_atoi(argv[i]) == 0 && argv[i][0] != '0'))
			exit_with_error("Error\n");
		i++;
	}
	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
			i++;
		else
			break ;
		if (i == (argc - 1))
			exit_with_error("argument is tried\n");
	}
}
