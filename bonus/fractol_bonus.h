/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:20:51 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/24 20:41:10 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../fractol.h"

void	handle_mandel_bonus_pixels(int x, int y, t_fractal *fractal);
int		psychedelics_julia(int keysym, t_fractal *fractal);
int		psychedelics_mandel(int keysym, t_fractal *fractal);
int		key_julia_bonus_handler(int keysym, t_fractal *fractal);
int		key_mandel_bonus_handler(int keysym, t_fractal *fractal);

#endif