/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:02:39 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 19:25:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	int					nb;
	t_list				*members;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	long				start_time;
	int					must_eat;
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
	long			last_msec;
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
long				timestamp(void);
void				destroy_all_mutex(t_args *args);
void				unlock_all_mutex(t_args *args);
void				lock_all_mutex(t_args *args);
void				iter_mutex(t_args *args, int f(pthread_mutex_t *mutex));
void				set_action_tf(t_philo *philo);
void				set_action_d(t_philo *philo);
void				set_action_s(t_philo *philo);
void				set_action_t(t_philo *philo);
void				set_action_e(t_philo *philo);
void				set_action_ts_str(t_philo *philo, t_action action,
						long ts, char *action_str);
int					w8_for(t_args *args);
void				ft_sleep(int time_micro);

#endif
