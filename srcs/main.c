#include "../includes/philosophers.h"

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

long	get_time(t_args *args)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	return (tv.tv_usec - args->start_time);
}

void	*eat(t_philo *philo)
{
	//pthread_mutex_lock(&g_mutex);
	philo->action = EAT;
	printf("%ld Philosopher %d is eating\n", get_time(philo->args), philo->id);
	usleep(500000);
	//test(philo);
	//pthread_mutex_unlock(&g_mutex);
	pthread_exit(0);
	return (NULL);
}

void	*start(void *v)
{
	t_philo			*philo;

	philo = (t_philo *)v;
	printf("%ld New Philosopher %d\n", get_time(philo->args), philo->id);
	usleep(500000);
	//pthread_mutex_unlock(&g_mutex);
	eat(philo);
	return (NULL);
}

int	create_thread(t_philo *philo)
{
	pthread_attr_t	*params;
	void			*arg;
	void			*ret;

	params = NULL;
	arg = philo;
	if (pthread_create(&(philo->thread), params, start, arg) != 0)
	{
		printf("Unable to create thread.\n");
		return (1);
	}
	/*if (pthread_mutex_init(PTHREAD_MUTEX_INITIALIZER, NULL) != 0)
	{
		printf("Unable to create mutex.\n");
		return (1);
	}*/
	//pthread_detach(philo->thread);
	/*if (pthread_join(philo->thread, &ret) != 0)
	{
		printf("Unable to join thread.\n");
		return (3);
	}
	printf("thread exited with '%s'\n", (char *)ret);*/
	return (0);
}

void	join_thread(void *v)
{
	t_philo	*philo;
	int		id;
	void	*ret;

	philo = (t_philo *)((t_list *)v)->content;
	id = philo->id;
	if (pthread_join(philo->thread, &ret) != 0)
	{
		printf("Unable to join thread.\n");
		return ;
	}
	printf("Philosopher %d died\n", id);
}

void	join_threads(t_args *args)
{
	ft_lstiter(args->members, join_thread);
}

int	main(int ac, char **av)
{
	t_args	*arg;

	arg = args(ac, av);
	if (!arg)
		return (1);
	init_philo(arg);
	join_threads(arg);
	printf("END\n");
	ft_lstclear(&(arg->members), free);
	free(arg);
	(void)ac;
	(void)av;
	return (0);
}
