/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:37:07 by afromont          #+#    #+#             */
/*   Updated: 2024/01/24 10:09:14 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../fract/minilibx-linux/mlx.h"

int     ft_isdigit(int c)
{
        if (c >= '0' && c <= '9')
                return (1);
        return (0);
}

double	ft_atof(char *str)
{
	double	nb;
	double	scale;
	double	sign;

	nb = 0;
	scale = 0.1;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		nb = (nb * 10) + (*(str++) - '0');
	if (*str != '.')
		return (sign * nb);
	while (ft_isdigit(*(++str)))
	{
		nb += (*str - '0') * scale;
		scale = scale / 10;
	}
	return (sign * nb);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atof(argv[2]); 
			fractal.julia_y = ft_atof(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
