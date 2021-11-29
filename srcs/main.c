#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_args	*arg;

	arg = args(ac, av);
	if (!arg)
		return (1);
	init_philo(arg);
	join_threads(arg);
	ft_lstclear(&(arg->members), free);
	free(arg->forks);
	free(arg->mutexs);
	free(arg);
	(void)ac;
	(void)av;
	return (0);
}
