CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = 	mandatory/main.c mandatory/events_mandelbrot.c mandatory/events_julia.c	mandatory/julia.c \
		mandatory/mandelbrot.c	mandatory/parsing.c	mandatory/tools.c \
		mandatory/parsing_tools.c mandatory/math_tools.c mandatory/mandel_initialization.c \
		mandatory/julia_initialization.c

O_FILES = $(FILES:.c=.o)

MLX_COMP = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

NAME = fractol

all : $(NAME)

$(NAME) : $(O_FILES)
			$(CC) $(O_FILES) $(CFLAGS) -o $@ $(MLX_COMP)

clean :
		rm -rf $(O_FILES)

fclean : clean
			rm -f $(NAME)

git	:	
		git add .; git commit -m "FRACTOL"; git push 

re : fclean all

.PHONY : all clean fclean re