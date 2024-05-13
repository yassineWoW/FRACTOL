/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:19:33 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/13 14:48:10 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(char *argv[])
{
	if (check_coordinate(argv[2]) || check_coordinate(argv[3]))
	{
		printf("hoho\n");
		ft_error();
	}
	else
		printf("hehe julia\n");
}
