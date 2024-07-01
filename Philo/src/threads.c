/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:54:08 by afromont          #+#    #+#             */
/*   Updated: 2024/03/09 10:56:18 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	check_finish(t_data *data, int philo_nb)
{
	int		i;
	int		finish;

	i = 0;
	finish = 0;
	while (1)
	{
		pthread_mutex_lock(&data->death);
		if (finish == philo_nb || data->dead)
		{
			pthread_mutex_unlock(&data->death);
			break ;
		}
		pthread_mutex_unlock(&data->death);
		pthread_mutex_lock(&data->time_eaten);
		if (data->philos[i].time_eaten == data->nb_meals)
			finish++;
		pthread_mutex_unlock(&data->time_eaten);
		i = (i + 1) % philo_nb;
	}
}

void	*check_meals(void *data_struct)
{
	t_data	*data;
	int		philo_nb;

	data = (t_data *)data_struct;
	pthread_mutex_lock(&data->lock);
	philo_nb = data->nb_philo;
	pthread_mutex_unlock(&data->lock);
	check_finish(data, philo_nb);
	pthread_mutex_lock(&data->death);
	data->dead = true;
	pthread_mutex_unlock(&data->death);
	return (NULL);
}

void	*routine(void *philosoph)
{
	t_philo	*philo;

	philo = (t_philo *)philosoph;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (check_dead(philo))
			break ;
	}
	return (NULL);
}
