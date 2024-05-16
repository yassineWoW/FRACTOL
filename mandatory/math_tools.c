/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:02:11 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/15 18:49:05 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// (0-799) -> (-2 - 2)

int		scale_coordinates(double unscaled_num, double new_min, double new_max ,double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min; 
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

	result.x = (z.x * z.x) - (z.y *z.y);
	result.y = 2 * z.x + z.y;

	return (result);
}