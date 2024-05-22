/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:11 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/21 18:35:26 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// (0-799) -> (-2 - 2)

double		scale_coordinates(double unscaled_num, double new_min, double new_max ,double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min); 
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;
	
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;

	return (result);
}

double square_z(double z)
{
	double result;

	result = z * z;
	return (result);
}
void	my_pixel_put(int x, int y, t_img *img, unsigned int color)
{
	int offset;
	
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

unsigned int coloring(unsigned int a, unsigned int r, unsigned int g, unsigned int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}