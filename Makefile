CC 			= 	gcc
NAME		=	philosophers
INCLUDES	=	includes/philosophers.h
SRCS		=	srcs/main.c srcs/check_args.c srcs/ft_atoi_ultimate.c $(wildcard srcs/*/*.c)

OBJS 		=	$(SRCS:.c=.o)

#CFLAGS		=	-Wall -Wextra -g3 -fsanitize=address
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall -Wextra -g3 -fsanitize=address

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) ${CFLAGS} -pthread $(OBJS) -o $(NAME)
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
