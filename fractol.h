#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
#include <X11/x>

typedef struct s_img
{
	void	*img_ptr; // pointer to the image struct
	char	*pixel_ptr; //points to the pixels
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



int		ft_isdigit(int c);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	set_choice(int argc, char *argv[]);
long	ft_atoi(const char *string);
double	ft_atod(const char *string);
int		check_coordinate(char *num);
void	mandelbrot_check(char *argv[]);
void	julia_check(char *argv[]);
void	ft_error(void);
void	julia(char *argv[]);
void	mandelbrot(void);
void	check_duplicate(char *num);
double		scale_coordinates(double unscaled_num, double new_min, double new_max ,double old_min, double old_max);
void	my_pixel_put(int x, int y, t_img *img, int color);
void	data_init(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);


#endif