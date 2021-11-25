#include "../includes/philosophers.h"

#define MARGIN_OF_ERROR 10000
#define LEFTFORK(n) n
#define RIGHTFORK(n, max) (n + 1) % max

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*start(t_philo *philo)
{
	int			waiting;
	size_t		i;
	t_timeval	tv;
	t_timezone	tz;

	philo->last_usec = tv.tv_usec;
	philo->last_sec = tv.tv_sec;
	while (1)
	{
		waiting = 1;
		printf("[%d] THINKING\n", philo->id);
		while (waiting)
		{
			gettimeofday(&tv, &tz);
			if (tv.tv_sec - philo->last_usec >= 4 && philo->last_sec - MARGIN_OF_ERROR > philo->last_usec)
			{
				printf("[%d] DIE AFTER [%lds%ldu]\n", philo->id, tv.tv_sec - philo->last_sec, tv.tv_usec - philo->last_usec);
				exit(0);
			}
			// else
				// printf("last time %ld tv_usec %ld difference %ldu%ld\n", last_second, tv.tv_sec, tv.tv_sec - last_second, tv.tv_usec - last_usecond);
			pthread_mutex_lock(&g_mutex);
			/*if (ISLEFT_FREE(philo->id) && ISRIGHT_FREE(philo->id))
			{
				//forks[LEFTFORK(n)] = TAKEN;
				//forks[RIGHTFORK(n)] = TAKEN;
				printf("[%d] TAKE FORK %d and %d\n", philo->id, LEFTFORK(philo->id), RIGHTFORK(philo->id));
				waiting = 0;
			}*/
			pthread_mutex_unlock(&g_mutex);
		}
		printf("\033[0;36m[%d] EATING\n\033[0m", philo->id);
		usleep(2000000);
		pthread_mutex_lock(&g_mutex);
		printf("[%d] REALEASE FORKS %d and %d\n", philo->id, LEFTFORK(philo->id), RIGHTFORK(philo->id, philo->args->nb));
		//forks[LEFTFORK(n)] = FREE;
		//forks[RIGHTFORK(n)] = FREE;
		pthread_mutex_unlock(&g_mutex);
		printf("[%d] SLEEPING\n", philo->id);
		usleep(2000000);
		gettimeofday(&tv, &tz);
		philo->last_sec = tv.tv_sec;
		philo->last_usec = tv.tv_usec;
	}
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
	printf("Philosopher %d died with exit %d\n", id, (int) ret);
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
