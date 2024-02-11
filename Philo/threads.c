#include "philo.h"


void init_thread(t_data *data)
{
    size_t i;
    pthread_t thread;

    i = 0;
    data->start_time = gettimeofday;
    while (i <= data->nb_philo)
    {
        if(pthread_create(data->tid[i], NULL, *routine, &data->philo[i]) == 0)
            error("Error\n Impossible to create threads!");
        i++;
    }
    i = 0
    while (i <= data->nb_philo)
    {
        if(pthread_join(data->tid[i], NULL))
            error("Error\n Impossible to join threads!");

    }
    
}