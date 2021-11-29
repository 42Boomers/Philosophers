CC 			= 	gcc
NAME		=	philosophers
INCLUDES	=	includes/philosophers.h
SRCS		=	srcs/main.c \
				srcs/action.c \
				srcs/threads.c \
				srcs/thread_dead.c \
				srcs/mutex.c \
				srcs/check_args.c \
				srcs/ft_atoi_ultimate.c \
				srcs/get_philo.c \
				srcs/utils.c \
				srcs/lst/ft_lstmap.c \
				srcs/lst/ft_lstiter.c \
				srcs/lst/ft_lstlast.c \
				srcs/lst/ft_lstdelone.c \
				srcs/lst/ft_lstadd_back.c \
				srcs/lst/ft_lstnew.c \
				srcs/lst/ft_lstadd_front.c \
				srcs/lst/ft_lstclear.c \
				srcs/lst/ft_lstsize.c \
				srcs/init/philo_init.c

OBJS 		=	$(SRCS:.c=.o)

#CFLAGS		=	-Wall -Wextra -g3 -fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror

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
