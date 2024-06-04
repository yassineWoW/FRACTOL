/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mandelbrot_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:08:50 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/25 16:03:06 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	close_mandel_handler(t_fractal *fra)
{
	mlx_destroy_image(fra->mlx_connection, fra->img.img_ptr);
	mlx_destroy_window(fra->mlx_connection, fra->mlx_window);
	mlx_destroy_display(fra->mlx_connection);
	free(fra->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	psychedelics_mandel(int keysym, t_fractal *fra)
{
	if (keysym == XK_r)
		fra->r_value += 15;
	else if (keysym == XK_R)
		fra->r_value -= 15;
	else if (keysym == XK_b)
		fra->b_value += 15;
	else if (keysym == XK_B)
		fra->b_value -= 15;
	else if (keysym == XK_g)
		fra->g_value += 15;
	else if (keysym == XK_G)
		fra->g_value -= 15;
	return (0);
}

int	key_mandel_bonus_handler(int keysym, t_fractal *fra)
{
	if (keysym == XK_Escape)
		close_mandel_handler(fra);
	else if (keysym == XK_Left)
		fra->s_x -= (0.5 * fra->zoom);
	else if (keysym == XK_Right)
		fra->s_x += (0.5 * fra->zoom);
	else if (keysym == XK_Up)
		fra->s_y -= (0.5 * fra->zoom);
	else if (keysym == XK_Down)
		fra->s_y += (0.5 * fra->zoom);
	else if (keysym == XK_KP_Add)
		fra->iterations += 10;
	else if (keysym == XK_KP_Subtract)
		fra->iterations -= 10;
	else
		psychedelics_mandel(keysym, fra);
	fractal_mandel_renderer(fra);
	return (0);
}

int	mouse_mandel_handler(int button, int x, int y, t_fractal *fra)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = (double)x / WIDTH;
	mouse_y = (double)y / HEIGHT;
	if (button == Button4)
	{
		fra->zoom *= 0.9;
		fra->s_x += (mouse_x - 0.5) * fra->zoom;
		fra->s_y += (mouse_y - 0.5) * fra->zoom;
		fractal_mandel_renderer(fra);
	}
	else if (button == Button5)
	{
		fra->zoom *= 1.1;
		fra->s_x += (mouse_x - 0.5) * fra->zoom;
		fra->s_y += (mouse_y - 0.5) * fra->zoom;
		fractal_mandel_renderer(fra);
	}
	return (0);
}

void	mandel_events_init(t_fractal *fra)
{
	mlx_hook(fra->mlx_window,
		KeyPress,
		KeyPressMask,
		&key_mandel_bonus_handler,
		fra);
	mlx_hook(fra->mlx_window,
		DestroyNotify,
		StructureNotifyMask,
		&close_mandel_handler,
		fra);
	mlx_hook(fra->mlx_window,
		ButtonPress,
		ButtonPressMask,
		mouse_mandel_handler,
		fra);
}
