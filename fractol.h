/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yimizare <yimizare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:56:19 by yimizare          #+#    #+#             */
/*   Updated: 2024/05/26 14:51:01 by yimizare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img_ptr;
	void	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void			*mlx_connection;
	void			*mlx_window;
	t_img			img;
	double			out_of_bounds;
	int				iterations;
	double			s_x;
	double			s_y;
	double			zoom;
	double			julia_x;
	double			julia_y;
	double			ma_x;
	double			mi_x;
	double			ma_y;
	double			mi_y;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	r_value;
	unsigned int	b_value;
	unsigned int	g_value;
	double			x;
	double			y;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

# define WIDTH  800			
# define HEIGHT  800				
# define BLACK	0x000000	// RGB(0, 0, 0)
# define WHITE	0xFFFFFF	// RGB(255, 255, 255)
# define RED		0xFF0000	// RGB(255, 0, 0)					
# define GREEN	0x00FF00	// RGB(0, 255, 0)
# define BLUE	0x0000FF	// RGB(0, 0, 255)
# define YELLOW  0x00FFFF    // (0, 255, 255)
# define MAGNETA_BURST 0xFF00FF
# define LIME_SHOCK    0xCCFF00
# define NEON_ORANGE   0xFF6600
# define NEON_TOKYO    0x660066
# define AQUA_DREAM    0x33CCCC
# define HOT_PINK      0xFF6682
# define CYAN		  0x00FFFF
# define ELECTRIC_BLUE 0x0066FF

int				ft_isdigit(int c);
int				ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			set_choice(int argc, char *argv[]);
long			ft_atoi(const char *string);
double			ft_atod(const char *string);
int				check_coordinate(char *num);
void			mandelbrot_check(char *argv[]);
void			julia_check(char *argv[]);
void			ft_error(void);
void			my_mlx_error(void);
void			colors(t_fractal *fra);
void			julia_init(char *argv[]);
void			julia(char *argv[]);
void			mandelbrot(void);
void			check_duplicate(char *num);
void			my_pixel_put(int x, int y, t_img *img, unsigned int color);
double			scale(double u_num, double n_min, double n_max, double o_max);
unsigned int	coloring(unsigned int a, unsigned int r,
					unsigned int g, unsigned int b);

// init
void			julia_data_init(t_fractal *fra);
void			julia_events_init(t_fractal *fra);
void			mandel_data_init(t_fractal *fra);
void			mandel_events_init(t_fractal *fra);

// redering
void			handle_mandel_pixels(int x, int y, t_fractal *fra);
void			handle_julia_pixels(int x, int y, t_fractal *fra);
void			fractal_julia_initialzer(t_fractal *fra);
void			fractal_mandel_initialzer(t_fractal *fra);
void			fractal_mandel_renderer(t_fractal *fra);
void			fractal_julia_renderer(t_fractal *fra);

// key_hadling
void			julia_events_init(t_fractal *fra);
int				key_mandel_handler(int keysym, t_fractal *fra);
int				key_julia_handler(int keysym, t_fractal *fra);
int				close_julia_handler(t_fractal *fra);
int				close_mandel_handler(t_fractal *fra);
int				mouse_julia_handler(int button, int x, int y, t_fractal *fra);
int				mouse_mandel_handler(int button, int x, int y, t_fractal *fra);
void			my_mlx_error(void);

t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);

#endif