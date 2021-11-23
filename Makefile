CC 			= 	gcc
NAME		=	philosophers
INCLUDES	=	includes/philosophers.h
SRCS		=	srcs/main.c srcs/ft_atoi_ultimate.c $(wildcard srcs/lst/*.c)

OBJS 		=	$(SRCS:.c=.o)

#CFLAGS		=	-Wall -Wextra -g3 -fsanitize=address
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall -Wextra -pthread -g3 -fsanitize=address

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) ${CFLAGS} $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
