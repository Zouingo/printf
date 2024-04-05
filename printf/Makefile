CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
HEADER = ft_printf.h

SOURCES = \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr_num.c \
	ft_putnbr_num_unsigned.c \
	ft_hex.c \
	ft_bighex.c \
	ft_printf.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f  $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re