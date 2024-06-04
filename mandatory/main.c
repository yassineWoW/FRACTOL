/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:30 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/24 21:49:12 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale(double u_num, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * (u_num - 0) / (o_max - 0) + n_min);
}

int	main(int argc, char *argv[])
{
	if (argc < 2 || argc > 4)
		ft_error();
	set_choice(argc, argv);
	return (0);
}
