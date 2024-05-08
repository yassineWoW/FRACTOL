/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:31:32 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/08 18:51:11 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct s_complex
{
	double	real;
	double	i;
}		t_complex;


#endif