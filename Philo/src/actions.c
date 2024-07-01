/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:54:20 by afromont          #+#    #+#             */
/*   Updated: 2024/02/23 12:11:19 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->dead)
	{
		pthread_mutex_unlock(&philo->data->death);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->death);
	pthread_mutex_lock(&philo->data->lock);
	if (get_time() - philo->last_meal > (size_t)philo->data->time_die)
	{
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_lock(&philo->data->death);
		philo->data->dead = true;
		pthread_mutex_unlock(&philo->data->death);
		printf_monitoring(philo, "died", B_RED, true);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (false);
}

void	eating(t_philo *philo)
{
	if (check_dead(philo))
		return ;
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	printf_monitoring(philo, "has taken a fork", B_WHITE, false);
	printf_monitoring(philo, "has taken a fork", B_WHITE, false);
	if (check_dead(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	printf_monitoring(philo, "is eating", B_YELLOW, false);
	philo->last_meal = get_time();
	ft_usleep(philo->data->time_eat * 1000);
	pthread_mutex_lock(&philo->data->time_eaten);
	philo->time_eaten++;
	pthread_mutex_unlock(&philo->data->time_eaten);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->data->lock);
	i = philo->data->time_sleep;
	pthread_mutex_unlock(&philo->data->lock);
	if (check_dead(philo))
		return ;
	printf_monitoring(philo, "is sleeping", B_CYAN, false);
	while (i)
	{
		if (check_dead(philo))
			return ;
		ft_usleep(1000);
		i--;
	}
}

void	thinking(t_philo *philo)
{
	if (check_dead(philo))
		return ;
	printf_monitoring(philo, "is thinking", B_GREEN, false);
}
