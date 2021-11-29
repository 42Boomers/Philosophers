#include "../includes/philosophers.h"

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
