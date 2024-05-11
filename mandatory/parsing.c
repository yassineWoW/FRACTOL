/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:14 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/11 20:40:58 by yimizare         ###   ########.fr       */
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

void	julia_check(char *argv[])
{
	if (ft_strlen(argv[1]) == 1)
	{
		if (argv[1][0] == 'J' || argv[1][0] == '2')
		{
			julia(argv);
		}
		else
			ft_error();
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		julia(argv);
	}
	else
		ft_error();
}

void	mandelbrot_check(char *argv[])
{
	if (ft_strlen(argv[1]) == 1)
	{
		if (argv[1][0] == 'M' || argv[1][0] == '1')
			mandelbrot(argv);
		else
			ft_error();
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mandelbrot(argv);
	else
		ft_error();
}

void	set_choice(int argc, char *argv[])
{
	if (argc == 2)
		mandelbrot_check(argv);
	else if (argc == 4)
		julia_check(argv);
	else
		ft_error();
}

int		check_coordinate(char *num)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (num[i] == '.')
		return (1);
	while (num[i] != '\0')
	{
		if (num[i] == '.' || num[i] == '+' || num[i] == '-')
		{
			flag = 1;
			i++;
		}
		if ((num[i] == '.' || num[i] == '+' || num[i] == '-') && flag == 1)
			return (1);
		i++;
	}
	i =0;
	while (num[i] != '\0')
	{
		if ((num[i] != '.' && num[i] != '+' && num[i] != '-') && !ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}
