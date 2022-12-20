NAME=libftprintf.a

CC=cc
CFLAGS=-Wall -Werror -Wextra
RM=rm -f
MAKE_LIBFT=make -C ./libft

SRCS=ft_printf.c
OBJS=$(SRCS:c=o) libft/libft.a
DEPS=ft_printf.h libft/libft.h 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:c=o)

all: $(NAME) libft/libft.a
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) libft/libft.a
libft/libft.a:
	$(MAKE_LIBFT) all
clean:
	$(MAKE_LIBFT) clean
	$(RM) $(OBJS)
fclean:
	$(MAKE_LIBFT) fclean
	$(RM) $(OBJS) $(NAME) ft_printf
re: fclean all

compile: re
	clear
	$(CC) $(CFLAGS) -o ft_printf main.c libftprintf.a libft/libft.a
	./ft_printf
debug: re
	clear
	$(CC) $(CFLAGS) -g -o ft_printf main.c libftprintf.a libft/libft.a
.PHONY: all fclean clean
