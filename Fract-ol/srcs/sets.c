/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:15:49 by afromont          #+#    #+#             */
/*   Updated: 2024/01/25 10:26:57 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate(t_complex *z, t_complex *c, int max_iter)
{
	double	x2;
	double	y2;
	double	tmp;
	int		i;

	i = 0;
	x2 = z->r * z->r;
	y2 = z->i * z->i;
	while ((x2 + y2 <= 4.0) && (i < max_iter))
	{
		tmp = z->r;
		z->r = x2 - y2 + c->r;
		z->i = (2 * z->i * tmp) + c->i;
		x2 = z->r * z->r;
		y2 = z->i * z->i;
		i++;
	}
	return (i);
}

int	mandelbrot(t_state *state, t_complex *coord)
{
	t_complex	z;

	z.r = 0;
	z.i = 0;
	return (iterate(&z, coord, state->max_iter));
}

int	julia(t_state *state, t_complex *coord)
{
	t_complex	z;

	z.r = coord->r;
	z.i = coord->i;
	return (iterate(&z, &(state->julia_c), state->max_iter));
}
