/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:16:00 by afromont          #+#    #+#             */
/*   Updated: 2024/01/25 10:14:37 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fractol(int argc, char **argv)
{
	t_state	state;

	init_state(&state);
	if (parse_and_set(argc, argv, &state))
	{
		ft_putstr_fd(ERRORMANDELBROT, 1);
		ft_putstr_fd(ERRORJULIA, 1);
		return (1);
	}
	if (init_mlx(&state))
	{
		ft_putstr_fd("error: failed to init mlx\n", 1);
		return (1);
	}
	init_mlx_hooks(&state);
	mlx_loop(state.mlx_ptr);
	free_mlx(&state);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("error: argument", 1);
		return (0);
	}
	return (fractol(argc, argv));
}
