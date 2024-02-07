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

typedef struct	s_var
{
	size_t	number_of_philosopher;
	size_t 	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_times_each_philosopher_must_eat;
}	t_var;

typedef struct s_listphilo
{
	pthread_t	*id_philo;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	struct s_listphilo	*next;
}	t_listphilo;

typedef struct s_philo
{
	int	thread;
	int	eating;
	int take_eat;
	size_t start_time;
	int	*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	t_var var;
	t_listphilo	list;
}	t_philo;



void	init_struct(t_philo *data, int nb, int die, int eat, int sleep, int nb_eat);

void	initphilo(t_philo *nbphilo);

void	error(char *str);

void	check_error(int argc, char **argv);

void	*test(void *arg);

int     ftatoi(const char *ptr);

t_philo create_node(pthread_t tid);

t_philo init_list(size_t nbphilo);

#endif
