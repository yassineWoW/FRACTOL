#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx.h"
# include <X11/keysym.h>

typedef struct s_complex
{
	double	z;
	double	i;
	// fractal id
	// mlx stuff;
	void	*mlx_connextion; // to initialize the mlx connnection;
	void	*mlx_window; // pointer for the window
	
	// image;
	// hooks value;

} t_complex;


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
void	mandelbrot(char *argv[]);
void	check_duplicate(char *num);


#endif