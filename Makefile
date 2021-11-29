CC 			= 	gcc
NAME		=	philosophers
INCLUDES	=	philo/includes/philosophers.h
SRCS		=	philo/srcs/main.c \
				philo/srcs/action.c \
				philo/srcs/threads.c \
				philo/srcs/thread_dead.c \
				philo/srcs/mutex.c \
				philo/srcs/check_args.c \
				philo/srcs/ft_atoi_ultimate.c \
				philo/srcs/get_philo.c \
				philo/srcs/utils.c \
				philo/srcs/lst/ft_lstmap.c \
				philo/srcs/lst/ft_lstiter.c \
				philo/srcs/lst/ft_lstlast.c \
				philo/srcs/lst/ft_lstdelone.c \
				philo/srcs/lst/ft_lstadd_back.c \
				philo/srcs/lst/ft_lstnew.c \
				philo/srcs/lst/ft_lstadd_front.c \
				philo/srcs/lst/ft_lstclear.c \
				philo/srcs/lst/ft_lstsize.c \
				philo/srcs/init/philo_init.c

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
