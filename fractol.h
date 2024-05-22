#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img_ptr; // pointer to the image struct
	void	*pixel_ptr; //points to the pixels
	int		bpp; //bytes per pixel;
	int		endian; // ??
	int		line_len;

}	t_img;

typedef struct s_fractal
{

	// fractal id
	// mlx stuff;	double	z;
	void	*mlx_connection; // to initialize the mlx connnection;
	void	*mlx_window; // pointer for the window
	// image;
	t_img	img;
	// hooks value;
	// calculations
	double	out_of_bounds;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	// RGB
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	unsigned int	r_value;
	unsigned int	b_value;
	unsigned int	g_value;

	// mouse coordinates
	double	x;
	double	y;
	
} t_fractal;


typedef struct	s_complex
{
	// real
		double	x;
	// imaginary
		double	y;
}	t_complex;

#define WIDTH  800			
#define HEIGHT  800
#define ZOOM_FACTOR 1.2
							
// primary colors					
#define BLACK	0x000000	// RGB(0, 0, 0)
#define WHITE	0xFFFFFF	// RGB(255, 255, 255)
#define RED		0xFF0000	// RGB(255, 0, 0)					
#define	GREEN	0x00FF00	// RGB(0, 255, 0)
#define BLUE	0x0000FF	// RGB(0, 0, 255)
#define YELLOW  0x00FFFF    // (0, 255, 255)

// Psychedelic colors
#define MAGNETA_BURST 0xFF00FF
#define LIME_SHOCK    0xCCFF00
#define NEON_ORANGE   0xFF6600
#define NEON_TOKYO    0x660066
#define AQUA_DREAM    0x33CCCC
#define HOT_PINK      0xFF6682
#define CYAN		  0x00FFFF
#define ELECTRIC_BLUE 0x0066FF


//parsing

int		ft_isdigit(int c);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	set_choice(int argc, char *argv[]);
long	ft_atoi(const char *string);
double	ft_atod(const char *string);
int		check_coordinate(char *num);
void	mandelbrot_check(char *argv[]);
void	julia_check(char *argv[], t_fractal fractal);
void	ft_error(void);

void	colors(t_fractal *fractal);
void	julia_init(char *argv[], t_fractal fractal);
void	julia(char *argv[], t_fractal *fractal);
void	mandelbrot(void);
void	check_duplicate(char *num);
double	scale_coordinates(double unscaled_num, double new_min, double new_max ,double old_min, double old_max);
void	my_pixel_put(int x, int y, t_img *img, unsigned int color);
// init
void	julia_data_init(t_fractal *fractal);
void	julia_events_init(t_fractal *fractal);
void	mandel_data_init(t_fractal *fractal);
void	mandel_events_init(t_fractal *fractal);

// redering
void	handle_mandel_pixels(int x, int y, t_fractal *fractal);
void	handle_julia_pixels(int x, int y, t_fractal *fractal);
void	fractal_julia_initialzer(t_fractal *fractal);
void	fractal_mandel_initialzer(t_fractal *fractal);
void	fractal_mandel_renderer(t_fractal *fractal);
void	fractal_julia_renderer(t_fractal *fractal);
unsigned int coloring(unsigned int a, unsigned int r, unsigned int g, unsigned int b);

// key_hadling
void	julia_events_init(t_fractal *fractal);
int		key_mandel_handler(int keysym, t_fractal *fractal);
int		key_julia_handler(int keysym, t_fractal *fractal);
int		close_julia_handler(t_fractal *fractal);
int		close_mandel_handler(t_fractal *fractal);
int		mouse_julia_handler(int button, int x, int y, t_fractal *fractal);
int		mouse_mandel_handler(int button, int x, int y, t_fractal *fractal);
void	my_mlx_error(void);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif