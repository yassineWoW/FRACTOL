CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = 	mandatory/main.c mandatory/events.c	mandatory/julia.c \
		mandatory/mandelbrot.c	mandatory/parsing.c	mandatory/tools.c \

O_FILES = $(FILES:.c=.o)

NAME = fractol

all : $(NAME)

$(NAME) : $(O_FILES)
			$(CC) $(CFLAGS) $(O_FILES) -o $@

clean :
		rm -rf $(O_FILES)

fclean : clean
			rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re