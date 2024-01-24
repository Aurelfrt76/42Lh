/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:13:27 by afromont          #+#    #+#             */
/*   Updated: 2024/01/23 11:13:38 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include "../LIB/ft_printf.h"

void	swap(int *a, int *b)
{
	int	buff;

	buff = *b;
	*b = *a;
	*a = buff;
}

int	*presort(int *array, int size)
{
	int	last_low;
	int	i;
	int	j;

	i = 0;
	j = 0;
	last_low = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (array[j] < array[last_low])
				last_low = j;
			j++;
		}
		if (array[i] != array[last_low])
			swap(&array[i], &array[last_low]);
		i++;
		j = i;
		last_low = i;
	}
	return (array);
}

int	*get_sorted_args(int argc, char *argv[])
{
	int	*int_array;
	int	i;
	int	j;

	j = 0;
	i = argc - 1;
	int_array = malloc(sizeof(int) * (argc - 1));
	while (i > 0)
	{
		int_array[j] = ft_atoi(argv[i]);
		i--;
		j++;
	}
	presort(int_array, argc - 1);
	return (int_array);
}

t_stack	*convert_and_fill_stack(t_stack *sa, int argc, char *argv[])
{
	int	*int_array;
	int	i;
	int	j;

	j = 0;
	i = argc - 1;
	int_array = get_sorted_args(argc, argv);
	while (i > 0)
	{
		if (ft_atoi(argv[i]) == int_array[j])
		{
			sa = push_stack(sa, j);
			j = 0;
			i--;
		}
		else
			j++;
	}
	free(int_array);
	return (sa);
}

int	main(int argc, char *argv[])
{
	t_stack	*sta;
	t_stack	*stb;

	ftgesterror(argc, argv);
	sta = new_stack();
	stb = new_stack();
	sta = convert_and_fill_stack(sta, argc, argv);
	if (argc == 3)
		two_args(&sta);
	else if (argc == 4)
		three_args(&sta);
	else if (argc == 5)
		four_args(&sta, &stb);
	else if (argc == 6)
		five_args(&sta, &stb);
	else if (argc > 6)
		radx(&sta, &stb);
	clear_stack(sta);
	clear_stack(stb);
	return (0);
}
