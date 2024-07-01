/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:33:03 by afromont          #+#    #+#             */
/*   Updated: 2024/02/23 12:11:06 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	init_threads(t_data *data)
{
	size_t	i;

	i = 0;
	if (data->nb_philo == 1)
	{
		printf("\033[1;37m0 1  has taken a fork\n");
		ft_usleep(data->time_die * 1000);
		printf("\033[1;31m%li 1 died\n\033[0m", data->time_die);
		return ;
	}
	while (i < data->nb_philo)
	{
		pthread_create(&data->philos[i].thread, NULL,
			routine, &data->philos[i]);
		i++;
	}
	if (data->nb_meals != -1)
	{
		pthread_create(&data->cook, NULL, check_meals, data);
		pthread_join(data->cook, NULL);
	}
	i = 0;
	while (i < data->nb_philo)
		pthread_join(data->philos[i++].thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data, argc, argv);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[1]) > 200)
		error_exit(&data, "Error Argument 1 is invalid");
	init_threads(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
