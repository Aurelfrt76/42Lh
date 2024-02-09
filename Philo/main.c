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
	t_data	data;

	//check_error(argc, argv);
	init_struct(&data,argv, argc);
	printf("%zu", data.nb_philo);
	printf("%zu", data.death_time);
	printf("%zu", data.eat_time);
	printf("%zu", data.sleep_time);
	printf("%zu", data.nb_eating);
	/*while (i < data.id_thread)
	{
		if (pthread_create(data.id_thread, NULL, ) != 0);
		error("erreur to init thread\n");
		else
			i++;
	}*/
	return (0);
}
