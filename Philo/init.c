#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->nb_philo)
	{
		data->philo->data = data; //revoir l'utilite de cette ligne
		data->philo[i].id = i + 1;
		data->philo[i].count_eat = 0;
		data->philo[i].time_die = data->death_time;
		data->philo[i].take_eat = 0;
		pthread_mutex_init(&data->philo[i].lock, NULL);
		i++;
	}
}

void	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	data->philo[0].l_fork = &data->forks[0];
	data->philo[0].r_fork = &data->forks[data->nb_philo - 1];
	i = 1;
	while (i < data->nb_philo)
	{
		data->philo[i].l_fork = &data->forks[i];
		data->philo[i].r_fork = &data->forks[i - 1];
		i++;
	}
}

void	init_struct(t_data *data, char **argv, int argc)
{
	data->nb_philo = ftatoi(argv[1]);
	data->death_time = ftatoi(argv[1]);
	data->eat_time = ftatoi(argv[1]);
	data->sleep_time = ftatoi(argv[4]);
	data->dead = 0;
	data->finished = 0;
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
	data->philo = malloc(sizeof(pthread_t) * data->nb_philo);
	data->tid = malloc(sizeof(pthread_t) * data->nb_philo);
	data->forks = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->philo || !data->forks || !data->tid)
		error("Error\n Failed to malloc");
	if (argc == 6)
		data->nb_eating = ftatoi(argv[5]);
	else
		data->nb_eating = -1;
	init_philo(&data);
	init_forks(&data);
}

