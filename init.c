#include "fractol.h"

void fractal_init(t_fractal *fractal)
{
	fractal->mlx_in = mlx-init();
	if (fractal->mlx_in == NULL)
		error_malloc();
	fractal->mlx_wind = mlx_new_window(fractal->mlx_in, WIDHT, HEIGHT, fractal->name)
	if (fract->mlx_wind == NULL)
	{
		mlx_destroy_display(fractal->mlx_in);
		free(fractal->mlx_in);
		error_malloc();
	}
	fractal->img.imgptr = mlx_new_image(fractal->mlx_in, WIDHT, HEIGHT);
	if (fractal->img.imgptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_in, fractal->mlx_wind);
		mlx_destroy_display(fractal->mlx_in);
		free(fractal->mlx_in);
		error_malloc();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.pixel_ptr, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	
}