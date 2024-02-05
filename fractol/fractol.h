/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:36:51 by afromont          #+#    #+#             */
/*   Updated: 2024/01/19 14:40:02 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../fract/minilibx-linux/mlx.h"

# define HEIGHT 1000
# define WIDTH 1000
# define ZOOM 1.0
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PINK 0xFF66FF
# define BLUE 0x3366FF
# define GREEN 0x00FF00
# define PURPLE 0x9933FF
# define ERROR_MESSAGE "ERROR\n YOU MUST ENTER EITHER \"./fractol mandelbrot\" OR \".fractol julia value_1 value_2\" THANKS\n"

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	char	*name;
	int		iterations_defintion;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	t_img	img;
}	t_fractal;

void	ft_putstr_fd(char *s, int fd);

void fractal_init(t_fractal *fractal);

void fractal_render(t_fractal *fractal);

double	ft_atof(char *str);

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

int     ft_isdigit(int c);

int		ft_strncmp(char *s1, char *s2, int n);

int	key_handler(int keysym, t_fractal *fractal);

int	close_handler(t_fractal *fractal);

int mouse_handler(int button,int x, int y, t_fractal *fractal);

int julia_track(int x, int y, t_fractal *fractal);

t_complex	sum_c(t_complex z, t_complex c);

t_complex	square_c(t_complex z);
 
#endif
