/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:01:29 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/20 19:52:59 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error(void)
{
	write(1, "wrong inputs try this :\n", 24);
	write(1, "		./fractol <the fractal's number>\n", 35);
	write(1, "(1): for Mandelbrot\n", 20);
	write(1, "(2): for Julia followed by the real and imaginary numbers\n", 58);
	exit(1);
}

void	set_choice(int argc, char *argv[])
{
	t_fractal fractal;

	if (argc == 2)
		mandelbrot_check(argv);
	else if (argc == 4)
		julia_check(argv, fractal);
	else
		ft_error();
}
