/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:11:11 by afromont          #+#    #+#             */
/*   Updated: 2024/02/07 14:11:15 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *str)
{
	printf("%s", str);
	exit(1);
}

void	check_error(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc != 6)
		error("invalid number of arguments\n");
	while (i <= 4)
	{
		if (ftatoi(argv[i++]) == 0)
			error("the arguments are invalid\n");
	}
}
