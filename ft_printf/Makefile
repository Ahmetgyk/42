NAME	= libftprintf.a

FILES	= ft_printf.c \
		  ft_printf_unsigned.c \
		  ft_printf_str.c \
		  ft_printf_ptr.c \
		  ft_printf_nbr.c \
		  ft_printf_hex.c \
		  

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

OFILES	= $(FILES:.c=.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(FILES)
	ar -r -c $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re