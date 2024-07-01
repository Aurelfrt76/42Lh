/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:53:53 by afromont          #+#    #+#             */
/*   Updated: 2024/02/23 12:10:39 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atoi(const char *str)
{
	size_t	i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - 48);
	if (str[i] != 0)
		error_exit(NULL, "Invalid arguments");
	return (result);
}

static void	init_data(t_data *data, int nb_philo, char **argv)
{
	data->nb_philo = nb_philo;
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_meals = ft_atoi(argv[5]) + 1;
	else
		data->nb_meals = -1;
	data->dead = false;
	data->forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	while (nb_philo--)
		pthread_mutex_init(&data->forks[nb_philo], NULL);
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->time_eaten, NULL);
	data->start_time = get_time();
}

static void	init_philos(t_data *data, int nb_philo)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * nb_philo);
	i = 0;
	while (i < nb_philo)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % nb_philo];
		data->philos[i].time_eaten = 0;
		data->philos[i].last_meal = data->start_time;
		i++;
	}
}

void	init(t_data *data, int argc, char **argv)
{
	int	nb_philo;

	if (argc == 5 || argc == 6)
	{
		nb_philo = ft_atoi(argv[1]);
		init_data(data, nb_philo, argv);
		init_philos(data, nb_philo);
	}
	else
		error_exit(NULL, CORRECT_SYNTAX);
}
