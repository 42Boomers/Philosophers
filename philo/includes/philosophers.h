#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>

# define FREE 0
# define TAKEN 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_args
{
	int					nb;
	t_list				*members;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					must_eat;
	int					*forks;
	pthread_mutex_t		*mutexs;
	pthread_mutex_t		mutex_print;
}	t_args;

typedef enum s_action
{
	ALIVE,
	EAT,
	SLEEP,
	THINK,
	TAKE_FORK,
	DEAD_ALONE,
	END
}	t_action;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	unsigned long	last_msec;
	t_action		action;
	int				times_eat;
	t_args			*args;
}	t_philo;

typedef struct timeval	t_timeval;
typedef struct timezone	t_timezone;

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
void				release_forks(t_philo *philo);
int					get_forks(t_philo *philo);
void				*start(void *arg);
void				join_threads(t_args *args);
int					create_thread(t_philo *philo);
unsigned long		timestamp(void);
void				destroy_all_mutex(t_args *args);
void				unlock_all_mutex(t_args *args);
void				lock_all_mutex(t_args *args);
void				iter_mutex(t_args *args, int f(pthread_mutex_t *mutex));
void				set_action(t_philo *philo, t_action action);
int					w8_for(t_args *args);

#endif
