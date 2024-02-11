/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:33:32 by afromont          #+#    #+#             */
/*   Updated: 2024/02/05 10:33:45 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"


typedef struct s_philo
{
	struct s_data	*data;
	pthread_mutex_t	lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	size_t	id;
	size_t	count_eat;
	size_t	time_die;
	size_t	take_eat;
	size_t	start_time;
}	t_philo;

typedef struct	s_data
{
	pthread_t	*tid;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
	size_t	nb_philo;
	size_t 	death_time;
	size_t	eat_time;
	size_t	sleep_time;
	size_t	nb_eating;
	size_t	dead;
	size_t	finished;
	size_t	start_time;
	//size_t	take_eat;
	//size_t	id;
	t_philo *philo;
}	t_data;




void	init_struct(t_data *data, char **argv, int argc);

void	init_philo(t_data *data);

void	error(char *str);

int	check_error(int argc, char **argv);

size_t     ftatoi(const char *ptr);

#endif
