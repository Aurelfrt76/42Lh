/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:54:20 by afromont          #+#    #+#             */
/*   Updated: 2024/02/23 12:11:19 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	error_exit(t_data *data, char *strerror)
{
	if (data)
		free_data(data);
	printf("%s\n", strerror);
	exit(EXIT_FAILURE);
}

size_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit(NULL, "gettimeofday() FAILURE\n");
	return ((tv.tv_sec * (size_t)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time / 1000)
		usleep(1);
}

void	printf_monitoring(t_philo *philo, char *str, char *color,
											bool death_message)
{
	pthread_mutex_lock(&philo->data->death);
	if (!philo->data->dead || death_message)
	{
		pthread_mutex_lock(&philo->data->write);
		if (philo->data->dead && !death_message)
		{
			pthread_mutex_unlock(philo->l_fork);
			pthread_mutex_unlock(philo->r_fork);
			pthread_mutex_unlock(&philo->data->death);
			return ;
		}
		pthread_mutex_unlock(&philo->data->death);
		printf("%s%zu %d %s\n%s", color, get_time() - philo->data->start_time,
			philo->id, str, RESET);
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	pthread_mutex_unlock(&philo->data->death);
}

void	free_data(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->lock);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->death);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}
