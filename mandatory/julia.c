/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:33 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/22 17:14:26 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	colors(t_fractal *fractal)
{
	fractal->red = 0 + fractal->r_value;
	fractal->blue = 0 + fractal->b_value;
	fractal->green = 0 + fractal->g_value;
}

void	julia_init(char *argv[], t_fractal fractal)
{
	if (check_coordinate(argv[2]) || check_coordinate(argv[3]))
		ft_error();
	else
		julia(argv, &fractal);
}
void	handle_julia_pixels(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	// z is actualy just the iteration amount
	i = 0;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	// c is the pixels coordinates and x and y are scaled to fit the mandelbrot set (-2, 2)
	// z.x = scale_coordinates((double)x, -2, +2, 0, WIDTH * fractal->zoom) + fractal->shift_x;
	// z.y = scale_coordinates((double)y, +2, -2, 0, HEIGHT * fractal->zoom) + fractal->shift_y;
	
	z.x = scale_coordinates((double)x, fractal->min_x, fractal->max_x, 0, WIDTH) * fractal->zoom + fractal->shift_x;
    z.y = scale_coordinates((double)y, fractal->min_y, fractal->max_y, 0, HEIGHT) * fractal->zoom + fractal->shift_y;
	// now we will check if our numbers get to infinity if we iterate through them they should stay bounded if they truly are in the mandelbrot set
		colors(fractal);
	while (i < fractal->iterations) // how many time are we iterating to check if we still in bounds
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->out_of_bounds) // if yes then we out of bounds and we not in mandelbrrot
		{
			//color = scale_coordinates(i, BLACK, WHITE, 0, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, coloring(0, fractal->red, fractal->green, fractal->blue)); //TO DO!
			return ;
		}
		fractal->red += 10;
		fractal->green += 10;
		fractal->blue += 10;
		i++;
	}
	// now we are in mandelbrot
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	fractal_julia_renderer(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_julia_pixels(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window, 
							fractal->img.img_ptr, 0, 0);
}

void	julia(char *argv[], t_fractal *fractal)
{
	fractal->julia_x = ft_atod(argv[2]);
	fractal->julia_y = ft_atod(argv[3]);
	
	fractal_julia_initialzer(fractal);
	fractal_julia_renderer(fractal);
	//mlx_mouse_hook(fractal->mlx_window, mouse_julia_handler, fractal);
	mlx_loop(fractal->mlx_connection);
}