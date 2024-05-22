/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:20:16 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/22 16:46:42 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_data_init(t_fractal *fractal)
{
	fractal->red = 0;
	fractal->blue = 0;
	fractal->green = 0;
	fractal->max_x = 2.0;
	fractal->min_x = -2.0;
	fractal->max_y = 2.0;
	fractal->min_y = -2.0;
	fractal->out_of_bounds = 4; // 2 square 2 c^2 = a^2 + b^2;
	fractal->iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->r_value = 0;
	fractal->g_value = 0;
	fractal->b_value = 0;
}

void	fractal_julia_initialzer(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();

	if (fractal->mlx_connection == NULL)
		my_mlx_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, "Julia");
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		my_mlx_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		my_mlx_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
										&fractal->img.bpp, 
										&fractal->img.line_len, 
										&fractal->img.endian);
	julia_data_init(fractal);
	julia_events_init(fractal);
}

