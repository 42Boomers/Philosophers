#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_args
{
	int		nb;
	t_list	*members;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
	long	start_time;
}	t_args;

typedef enum s_action
{
	EAT,
	SLEEP,
	THINK,
	DEAD,
	WAIT
}	t_action;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			fork;
	t_action	action;
	t_args		*args;
}	t_philo;

void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del) (void *));
void				ft_lstclear(t_list **lst, void (*del) (void *));
void				ft_lstiter(t_list *lst, void (*f) (void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f) (void *), void (del)
						(void *));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_lstdelone(t_list *lst, void (*del) (void *));
int					ft_atoi_ultimate(const char *str);

t_args				*args(int ac, char **av);
int					init_philo(t_args *args);
t_philo				*get_philo(t_args *args, int id);

#endif