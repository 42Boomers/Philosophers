#include "../includes/philosophers.h"

static t_args	*args_2(t_args *args)
{
	int			i;

	args->forks = malloc(sizeof(int) * args->nb);
	if (!args->forks)
	{
		printf("Can't malloc args->forks[]\n");
		return (0);
	}
	args->mutexs = malloc(sizeof(pthread_mutex_t) * args->nb);
	if (!args->mutexs)
	{
		printf("Can't malloc pthread_mutex_t[]\n");
		return (0);
	}
	i = 0;
	while (i < args->nb)
		pthread_mutex_init(&args->mutexs[i++], NULL);
	args->members = NULL;
	return (args);
}

static int	check_args(int ac, t_args *args)
{
	if (args->nb < 1 || args->time_die < 0 || args->time_eat < 0
		|| args->time_sleep < 0 || (ac >= 6 && args->must_eat < 0))
	{
		printf("All args must be valid numbers\n");
		return (1);
	}
	return (0);
}

static t_args	*args_ints(int ac, char **av, t_args *args)
{
	args->nb = ft_atoi_ultimate(av[1]);
	args->time_die = ft_atoi_ultimate(av[2]);
	args->time_eat = ft_atoi_ultimate(av[3]);
	args->time_sleep = ft_atoi_ultimate(av[4]);
	if (ac >= 6)
		args->must_eat = ft_atoi_ultimate(av[5]);
	else
		args->must_eat = -1;
	if (check_args(ac, args) != 0)
	{
		free(args);
		return (0);
	}
	return (args_2(args));
}

t_args	*args(int ac, char **av)
{	
	t_args			*args;

	args = malloc(sizeof(t_args));
	if (!args)
	{
		printf("Can't malloc t_args\n");
		return (0);
	}
	if (ac < 5)
	{
		printf("4 args minimum\n");
		free(args);
		return (0);
	}
	return (args_ints(ac, av, args));
}
