/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:48:09 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/22 20:49:02 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_julia_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int		key_julia_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_julia_handler(fractal);
	 if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_KP_Add)
		fractal->iterations += 10;
	else if (keysym == XK_KP_Subtract)
		fractal->iterations -= 10;
	fractal_julia_renderer(fractal);
	
	return 0;
}



int	mouse_julia_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (double)x / WIDTH;
	mouse_y = (double)y / HEIGHT;
	if (button == Button4)
	{
		fractal->zoom *= 0.9;
		fractal->shift_x += (mouse_x - 0.5) * fractal->zoom;
		fractal->shift_y += (mouse_y - 0.5) * fractal->zoom;
		fractal_julia_renderer(fractal);
	}
	else if (button == Button5)
	{
		fractal->zoom *= 1.1;
		fractal->shift_x += (mouse_x - 0.5) * fractal->zoom;
		fractal->shift_y += (mouse_y - 0.5) * fractal->zoom;
		fractal_julia_renderer(fractal);
	}
	return (0);
}

void	julia_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 
			KeyPress, 
			KeyPressMask, 
			&key_julia_handler, 
			fractal);
	mlx_hook(fractal->mlx_window, 
			DestroyNotify, 
			StructureNotifyMask, 
			&close_julia_handler, 
			fractal);
	mlx_hook(fractal->mlx_window,
	 		ButtonPress,
			ButtonPressMask,
			mouse_julia_handler, 
			fractal);
}