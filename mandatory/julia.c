/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:33 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/26 18:37:26 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	colors(t_fractal *fra)
{
	fra->r = 0 + fra->r_value;
	fra->b = 0 + fra->b_value;
	fra->g = 0 + fra->g_value;
}

void	julia_init(char *argv[])
{
	if (check_coordinate(argv[2]) || check_coordinate(argv[3]))
		ft_error();
	else
		julia(argv);
}

void	handle_julia_pixels(int x, int y, t_fractal *fra)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	c.x = fra->julia_x;
	c.y = fra->julia_y;
	z.x = scale((double)x, fra->mi_x, fra->ma_x, WIDTH) * fra->zoom + fra->s_x;
	z.y = scale((double)y, fra->mi_y, fra->ma_y, HEIGHT) * fra->zoom + fra->s_y;
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
	my_pixel_put(x, y, &fra->img, WHITE);
}

void	fractal_julia_renderer(t_fractal *fra)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_julia_pixels(x, y, fra);
		}
	}
	mlx_put_image_to_window(fra->mlx_connection,
		fra->mlx_window,
		fra->img.img_ptr, 0, 0);
}

void	julia(char *argv[])
{
	t_fractal	fra;

	fra.julia_x = ft_atod(argv[2]);
	fra.julia_y = ft_atod(argv[3]);
	fractal_julia_initialzer(&fra);
	fractal_julia_renderer(&fra);
	mlx_loop(fra.mlx_connection);
}
