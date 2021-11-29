#include "../includes/philosophers.h"

static int	check_dead(t_args *args)
{
	t_list	*iter;
	t_philo	*philo;

	iter = args->members;
	while (iter)
	{
		philo = (t_philo *)iter->content;
		if (philo->action == DEAD_ALONE)
			return (-2);
		if (philo->action == END)
			return (-1);
		iter = iter->next;
	}
	return (0);
}

int	w8_for(t_args *args)
{
	int	ret;

	ret = check_dead(args);
	while (!ret)
	{
		//usleep(4000);
		ret = check_dead(args);
	}
	return (ret);
}