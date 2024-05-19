CC = cc
CFLAGS = -Wall -Werror -Wextra


SRCS = ft_printf.c	ft_hexa.c	ft_num.c	ft_str.c	ft_putchar_fd.c	ft_putnbr_fd.c\

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

.PHONY:all clean fclean re

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c  $<

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

re: fclean all

clean:
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)


