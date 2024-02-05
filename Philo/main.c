/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:33:03 by afromont          #+#    #+#             */
/*   Updated: 2024/02/05 10:33:24 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int argc, char **argv)
{
	t_philo	data;
	int	i;

	i = 0;
	check_error(argc, argv);
	init_struct(&data, ftatoi(argv[1]), ftatoi(argv[2]), ftatoi(argv[3]), ftatoi(argv[4]), ftatoi(argv[5])); // todo ftatoi
	while (i < data.id_thread)
	{
		if (pthread_create(data.id_thread, NULL, ) != 0);
		error("erreur to init thread\n");
		else
			i++;
	}
	return (0);
}
