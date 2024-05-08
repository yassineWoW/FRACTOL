/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:35:26 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/08 20:00:31 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
	t_complex	z;
	t_complex	c;
	double		temp_real;
	int	i = 0;
	
	z.real = 0;
	z.i = 0;

	c.real = 0.25;
	c.i = 0.4;

	while (i < 42)
	{
		temp_real = (z.real * z.real) - (z.i * z.i);
		
		z.i = 2 * z.real * z.i;
		
		z.real = temp_real;
		
		z.real += c.real;
		z.i += c.i;

		printf("iteration n -> %d real %f imaginary %f\n", i, z.real, z.i);
		i++;
	}
}