/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:11:22 by afromont          #+#    #+#             */
/*   Updated: 2024/02/07 14:11:27 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_philo *data, int nb, int die, int eat, int sleep, int nb_eat)
{
	data->var.number_of_philosopher = nb;
	data->var.time_to_die = die;
	data->var.time_to_eat = eat;
	data->var.time_to_sleep = sleep;
	data->var.number_of_times_each_philosopher_must_eat = nb_eat;
}
void	initphilo(t_philo *data)
{
	size_t i;

	i = 0;
	while (i++ < data->var.number_of_philosopher)
		{
			if (pthread_create(&data->list.id_philo[i], NULL, test, NULL) == 0)
				error("erreur to init thread\n");
			else
			{	
				pthread_join(data->list.id_philo[i], NULL);
				printf("%zu", data->list.id_philo[i]);
			}
		}
}
/*
void *eating(void *arg)
{

	pthread_exit(0); //fonction non autorise
}

void *sleeping(void *arg)
{

	pthread_exit(0);
}

void *thinking(void *arg)
{

	pthread_exit(0);
}*/
