NAME=libftprintf.a

CC=cc
CFLAGS=-Wall -Werror -Wextra
RM=rm -f
MAKE_LIBFT=make -c ./libft

SRCS=ft_printf.c
OBJS=$(SRCS:c=o) libft/libft.a
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o ft_printf $(OBJS)
libft/libft.a:
	$(MAKE_LIBFT)
	$(MAKE_LIBFT) bonus
clean:
	$(MAKE_LIBFT) clean
	$(RM) $(OBJS)
fclean: clean
	$(MAKE_LIBFT) fclean
	$(RM) $(NAME)
