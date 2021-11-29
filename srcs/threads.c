#include "../includes/philosophers.h"

static void	join_thread(void *v)
{
	t_philo	*philo;
	void	*ret;

	philo = (t_philo *)v;
	if (pthread_join(philo->thread, &ret) != 0)
	{
		printf("Error : Unable to join thread for Philo %d.\n", philo->id);
		return ;
	}
}

void	join_threads(t_args *args)
{
	ft_lstiter(args->members, join_thread);
}

int	create_thread(t_philo *philo)
{
	pthread_attr_t	*params;
	void			*arg;

	params = NULL;
	arg = philo;
	if (pthread_create(&(philo->thread), params, start, arg) != 0)
	{
		printf("Error : Unable to create thread for Philo %d.\n", philo->id);
		return (1);
	}
	return (0);
}


void	iter_mutex(t_args *args, int f(pthread_mutex_t *mutex))
{
	int	i;

	i = 0;
	while (i < args->nb)
	{
		f(&args->mutexs[i++]);
	}
}

void	destroy_all_mutex(t_args *args)
{
	iter_mutex(args, pthread_mutex_destroy);
}

void	unlock_all_mutex(t_args *args)
{
	iter_mutex(args, pthread_mutex_unlock);
}

void	lock_all_mutex(t_args *args)
{
	iter_mutex(args, pthread_mutex_lock);
}
