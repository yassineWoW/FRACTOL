/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:22 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/16 19:19:03 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_error(void)
{
	write(2, "problem with memory allocation\n", 31);
	exit(1);
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;
	
	offset = ((y * img->line_len) + x + (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	data_init(t_fractal *fractal)
{
	fractal->out_of_bounds = 4; // 2 square 2 c^2 = a^2 + b^2;
	fractal->iterations = 42;
}

void	handle_pixels(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	// z is actualy just the iteration amount
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	
	// c is the pixels coordinates and x and y are scaled to fit the mandelbrot set (-2, 2)
	c.x = scale_coordinates(x, -2, 2, 0, WIDTH);
	c.y = scale_coordinates(y, 2, -2, 0, HEIGHT);
	
	// now we will check if our numbers get to infinity if we iterate through them they should stay bounded if they truly are in the mandelbrot set
	while (i < fractal->iterations) // how many time are we iterating to check if we still in bounds
	{
		z = sum_complex(square_complex(z), c);

		if (((z.x * z.x) + (z.y * z.y)) > fractal->out_of_bounds) // if yes then we out of bounds and we not in mandelbrrot
		{
			color = scale_coordinates(i, BLACK, WHITE, 0, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, color); //TO DO!
			return ;
		}
		i++;
	}
	// now we are in mandelbrot
	my_pixel_put(x, y, &fractal->img, CYAN);
	
	
}

void	fractal_renderer(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixels(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
void	fractal_initialzer(t_fractal *fractal, t_img *img)
{
	// mlx stuff;

	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		my_mlx_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, "Mandelbrot");
	
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		my_mlx_error();
	}
	img->img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (img->img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		my_mlx_error();
	}
	img->pixel_ptr = mlx_get_data_addr(&img->img_ptr, &img->bpp, &img->line_len, &img->endian);

	//events_init
	data_init(fractal);
}

void	mandelbrot(void)
{
	t_fractal	fractal;
	t_img		img;
	
	fractal_initialzer(&fractal, &img);
	fractal_renderer(&fractal);
	mlx_loop(fractal.mlx_connection); //for events (mouse click, keystrokes)
	
}
