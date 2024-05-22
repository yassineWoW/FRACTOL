/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:22 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/22 17:59:02 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_error(void)
{
	write(2, "problem with mlx memory allocation\n", 35);
	exit(1);
}

void	handle_mandel_pixels(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	//int			color;

	// z is actualy just the iteration amount
	//color = 0;
	i = 0;
	z.x = 0;
    z.y = 0;
	
	// c is the pixels coordinates and x and y are scaled to fit the mandelbrot set (-2, 2)
	c.x = scale_coordinates((double)x, fractal->min_x, fractal->max_x, 0, WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = scale_coordinates((double)y, fractal->min_y, fractal->max_y, 0, HEIGHT) * fractal->zoom + fractal->shift_y;
	
	colors(fractal);// now we will check if our numbers get to infinity if we iterate through them they should stay bounded if they truly are in the mandelbrot set
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
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_mandel_renderer(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_mandel_pixels(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window, 
							fractal->img.img_ptr, 0, 0);
}

void	mandelbrot(void)
{
	t_fractal	fractal;
	
	fractal_mandel_initialzer(&fractal);
	fractal_mandel_renderer(&fractal);
	mlx_loop(fractal.mlx_connection); //for events (mouse click, keystrokes)
}
