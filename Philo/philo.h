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

typedef struct s_philo
{
	pthread_t	thread;
	int	id_thread;
	int	eating;
	int take_eat;
	size_t start_time;
	int	*dead;
	t_var *var;
}	t_philo;

void	init_struct(t_var *data, int nb, int die, int eat, int sleep, int nb_eat);

void	error(char *str);

void	check_error(int argc, char **argv);

int     ftatoi(const char *ptr);

#endif
