CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = 	mandatory/main.c mandatory/events_mandelbrot.c mandatory/events_julia.c	mandatory/julia.c \
		mandatory/mandelbrot.c	mandatory/parsing.c	mandatory/tools.c \
		mandatory/parsing_tools.c mandatory/math_tools.c mandatory/mandel_initialization.c \
		mandatory/julia_initialization.c

FILES_BONUS = bonus/main_bonus.c bonus/events_mandelbrot_bonus.c bonus/events_julia_bonus.c	bonus/julia_bonus.c \
		bonus/mandelbrot_bonus.c	bonus/parsing_bonus.c \
		bonus/parsing_tools_bonus.c bonus/math_tools_bonus.c bonus/mandel_initialization_bonus.c \
		bonus/julia_initialization_bonus.c bonus/tools_bonus.c

O_FILES = $(FILES:.c=.o)

O_FILES_BONUS = $(FILES_BONUS:.c=.o)

MLX_COMP = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

NAME = fractol

NAME_BONUS = fractol_bonus 

all : $(NAME)

$(NAME) : $(O_FILES)
			$(CC) $(O_FILES) $(CFLAGS) -o $@ $(MLX_COMP)

$(NAME_BONUS) : $(O_FILES_BONUS)
			$(CC) $(O_FILES_BONUS) $(CFLAGS) -o $@ $(MLX_COMP)

clean :
		@rm -rf $(O_FILES) $(O_FILES_BONUS)

fclean : clean
		@rm -f $(NAME) $(NAME_BONUS)

bonus : $(NAME_BONUS)

git	:	
		git add .; git commit -m "FRACTOL"; git push 

re : fclean all

.PHONY : all clean fclean re