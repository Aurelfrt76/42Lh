#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define HEIGHT 1000
#define WIDTH 1000
#define ERROR_MESSAGE "ERROR\n YOU MUST ENTER EITHER \"./fractol MANDELBROT\" OR \".fractol JULIA value_1 value_2\" THANKS\n"
 

 typedef struct s_fractal
 {
	void	*mlx_in;
	void	*mlx_wind;
	char	*name;
	t_img	img;


 }	t_fractal;

 typedef struct	s_img
 {
	void	*imgptr;
	char	*pixel_ptr;
	int		bpp;
	int 	endian;
	int		line_len;
 }	t_img;

void	ft_putstr_fd(char *s, int fd);

int		ft_strncmp(char *s1, char *s2, size_t n);

#endif