/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:22 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/24 21:43:51 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_error(void)
{
	write(2, "problem with mlx memory allocation\n", 35);
	exit(1);
}

void	handle_mandel_pixels(int x, int y, t_fractal *fra)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = scale((double)x, fra->mi_x, fra->ma_x, WIDTH) * fra->zoom + fra->s_x;
	c.y = scale((double)y, fra->mi_y, fra->ma_y, HEIGHT) * fra->zoom + fra->s_y;
	colors(fra);
	while (i < fra->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fra->out_of_bounds)
		{
			my_pixel_put(x, y, &fra->img, coloring(0, fra->r, fra->g, fra->b));
			return ;
		}
		fra->r += 10;
		fra->g += 10;
		fra->b += 10;
		i++;
	}
	my_pixel_put(x, y, &fra->img, BLACK);
}

void	fractal_mandel_renderer(t_fractal *fra)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_mandel_pixels(x, y, fra);
		}
	}
	mlx_put_image_to_window(fra->mlx_connection,
		fra->mlx_window,
		fra->img.img_ptr, 0, 0);
}

void	mandelbrot(void)
{
	t_fractal	fra;

	fractal_mandel_initialzer(&fra);
	fractal_mandel_renderer(&fra);
	mlx_loop(fra.mlx_connection);
}
