CC=cc
#CFLAGS=-Wall -Werror -Wextra

printf: ft_printf.o
	$(CC) -o ft_printf ft_printf.o
