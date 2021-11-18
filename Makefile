CC 			= 	gcc
NAME		=	philosophers
LIB_PATH	=	libft/libft.a
INCLUDES	=	includes/philosophers.h
SRCS		=	srcs/main.c

OBJS 		=	$(SRCS:.c=.o)

#CFLAGS		=	-Wall -Wextra -g3 -fsanitize=address
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-Wall -Wextra

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	make -C libft
	$(CC) ${CFLAGS} $(OBJS) $(LIB_PATH) -o $(NAME)
clean:
	make $@ -C libft
	rm -f $(OBJS)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
