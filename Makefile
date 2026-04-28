NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCDIR	= srcs
INCDIR	= includes

SRCS	= ${SRCDIR}/ft_putchar.c \
		${SRCDIR}/ft_putstr.c \
		${SRCDIR}/ft_strlen.c \
		${SRCDIR}/ft_putnbr_base.c \
		${SRCDIR}/conversion.c \
		ft_printf.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $@ $(OBJS)

%.o:%.c
			$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
