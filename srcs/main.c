#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_args	*arg;

	arg = args(ac, av);
	if (!arg)
		return (1);
	init_philo(arg);
	if (w8_for(arg) != -2)
	{
		printf("W8 4 threads\n");
		join_threads(arg);
	} else {
		//unlock_all_mutex(arg);
		//lock_all_mutex(arg);
	}
	printf("END\n");
	ft_lstclear(&(arg->members), free);
	free(arg->forks);
	//destroy_all_mutex(arg);
	free(arg->mutexs);
	free(arg);
	(void)ac;
	(void)av;
	return (0);
}
