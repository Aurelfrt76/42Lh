#include "philo.h"

void	init_struct(t_var *data, int nb, int die, int eat, int sleep, int nb_eat)
{
	data->number_of_philosopher = nb;
	data->time_to_die = die;
	data->time_to_eat = eat;
	data->time_to_sleep = sleep;
	data->number_of_times_each_philosopher_must_eat = nb_eat;
}