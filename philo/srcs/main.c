#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_args	*arg;

	arg = args(ac, av);
	if (!arg)
		return (1);
	pthread_mutex_init(&arg->mutex_print, NULL);
	init_philo(arg);
	if (w8_for(arg) != -2)
		join_threads(arg);
	else
		pthread_mutex_lock(&arg->mutex_print);
	unlock_all_mutex(arg);
	destroy_all_mutex(arg);
	//pthread_mutex_unlock(&arg->mutex_print);
	//pthread_mutex_destroy(&arg->mutex_print);
	ft_lstclear(&(arg->members), free);
	free(arg->forks);
	free(arg->mutexs);
	free(arg);
	return (0);
}
