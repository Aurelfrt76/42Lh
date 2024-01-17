#include "fractol.h"

int main (int argc, char ** argv)
{
    t_fractal   fractal;

    if  (argc == 2 && (!ft_strncmp(argv[1], "MANDELBROT", 10) || argc == 4 && !ft_strncmp(argv[1], "JULIA", 5)))
    {
        fractal.name = argv[1];
        fractal_init(&fractal);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_initializ);



    }
    else 
    {
        ft_putstr_fd(ERROR_MESSAGE, 1).
        exit(EXIT_FAILURE); 
    }





}

