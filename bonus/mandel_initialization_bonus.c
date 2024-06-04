/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_initialization_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:01:02 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/25 15:39:25 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_error(void)
{
	write(2, "problem with mlx memory allocation\n", 35);
	exit(1);
}

void	mandel_data_init(t_fractal *fra)
{
	fra->out_of_bounds = 4.0;
	fra->iterations = 42;
	fra->s_x = 0.0;
	fra->s_y = 0.0;
	fra->mi_x = -2.0;
	fra->ma_x = 2.0;
	fra->mi_y = -2.0;
	fra->ma_y = 2.0;
	fra->zoom = 1.0;
	fra->r = 0;
	fra->g = 0;
	fra->b = 0;
	fra->r_value = 0;
	fra->g_value = 0;
	fra->b_value = 0;
}

void	fractal_mandel_initialzer(t_fractal *fra)
{
	fra->mlx_connection = mlx_init();
	if (fra->mlx_connection == NULL)
		my_mlx_error();
	fra->mlx_window = mlx_new_window(fra->mlx_connection, WIDTH,
			HEIGHT, "Mandelbrot");
	if (fra->mlx_window == NULL)
	{
		mlx_destroy_display(fra->mlx_connection);
		free(fra->mlx_connection);
		my_mlx_error();
	}
	fra->img.img_ptr = mlx_new_image(fra->mlx_connection, WIDTH, HEIGHT);
	if (fra->img.img_ptr == NULL)
	{
		mlx_destroy_window(fra->mlx_connection, fra->mlx_window);
		mlx_destroy_display(fra->mlx_connection);
		free(fra->mlx_connection);
		my_mlx_error();
	}
	fra->img.pixel_ptr = mlx_get_data_addr(fra->img.img_ptr,
			&fra->img.bpp,
			&fra->img.line_len,
			&fra->img.endian);
	mandel_data_init(fra);
	mandel_events_init(fra);
}
