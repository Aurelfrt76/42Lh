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
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <thread_db.h>
# include <stdbool.h>
# include <sys/time.h>

# define RESET "\033[0m"
# define B_RED "\033[1;31m"
# define B_GREEN "\033[1;32m"
# define B_YELLOW "\033[1;33m"
# define B_CYAN "\033[1;36m"
# define B_WHITE "\033[1;37m"

# define CORRECT_SYNTAX "Correct syntax :\n\t./philo <nb_philo>\
 <time_die> <time_eat> <time_sleep> \
[number_of_times_each_philosopher_must_eat]\n\
If confusion, check subject -> Global Rules\n"

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	size_t				last_meal;
	ssize_t				time_eaten;
	int					id;
}	t_philo;

typedef struct s_data
{
	t_philo				*philos;
	pthread_t			cook;
	size_t				nb_philo;
	size_t				time_die;
	size_t				time_eat;
	size_t				time_sleep;
	ssize_t				nb_meals;
	bool				dead;
	size_t				start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		write;
	pthread_mutex_t		death;
	pthread_mutex_t		time_eaten;
}	t_data;

void			init(t_data *data, int argc, char **argv);

long			ft_atoi(const char *str);

/*********** threads ***********/

void			*check_meals(void *data);

void			*routine(void *philo);

/*********** utils ***********/

void			error_exit(t_data *data, char *strerror);

size_t			get_time(void);

void			ft_usleep(size_t time);

void			printf_monitoring(t_philo *philo, char *str, char *color,
					bool death_message);

void			free_data(t_data *data);

/*********** actions ***********/

bool			check_dead(t_philo *philo);

void			eating(t_philo *philo);

void			sleeping(t_philo *philo);

void			thinking(t_philo *philo);

#endif