/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:25:28 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/25 21:17:04 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	julia_check(char *argv[])
{
	if (ft_strlen(argv[1]) == 1)
	{
		if (argv[1][0] == 'J' || argv[1][0] == '2')
			julia_init(argv);
		else
			ft_error();
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
		julia_init(argv);
	else
		ft_error();
}

void	mandelbrot_check(char *argv[])
{
	if (ft_strlen(argv[1]) == 1)
	{
		if (argv[1][0] == 'M' || argv[1][0] == '1')
			mandelbrot();
		else
			ft_error();
	}
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mandelbrot();
	else
		ft_error();
}

void	check_duplicate(char *num)
{
	int	i;
	int	flag[256];

	i = 0;
	while (i < 256)
	{
		flag[i] = 0;
		i++;
	}
	i = 0;
	while (num[i] != '\0')
	{
		if ((num[i] == '.' || num[i] == '+' || num[i] == '-'))
		{
			flag[(int)num[i]] = 1;
		}
		i++;
		if (1 == flag[(int)num[i]])
			ft_error();
	}
}

int	check_coordinate(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0' && (num[i] == ' ' || num[i] == '	'))
		i++;
	if (((ft_isdigit(num[i]) == 0)) && ((num[i] != '+') && (num[i] != '-')))
	{
		ft_error();
	}
	i++;
	while (num[i] != '\0')
	{
		if (!ft_isdigit(num[i]) && num[i] != ' '
			&& (num[i] != '.' || num[i + 1] == '\0'))
		{
			ft_error();
		}
		i++;
	}
	check_duplicate(num);
	return (0);
}
