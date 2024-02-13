NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =	ft_printf.c\
		ft_printf_utils.c

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

c: clean
clean:
	$(RM) $(OBJ)

f: fclean
fclean:clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all re fclean clean f c