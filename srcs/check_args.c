#include "../includes/philosophers.h"

int	check_args(int ac, t_args *args)
{
	if (!args->nb || *(args->nb) < 1 || !args->time_die || !args->time_eat
		|| !args->time_sleep || (ac >= 6 && !args->must_eat))
	{
		printf("all args must be valid numbers\n");
		return (1);
	}
	return (0);
}

t_args	*args(int ac, char **av)
{	
	t_args args;
	struct timeval	tv;
	struct timezone tz;

	if (ac < 5)
	{
		printf("4 args minimum\n");
		return (0);
	}
	gettimeofday(&tv, &tz);
	args.start_time = tv.tv_usec;
	args.nb = ft_atoi_ultimate(av[1]);
	args.time_die = ft_atoi_ultimate(av[2]);
	args.time_eat = ft_atoi_ultimate(av[3]);
	args.time_sleep = ft_atoi_ultimate(av[4]);
	if (ac >= 6)
		args.must_eat = ft_atoi_ultimate(av[5]);
	else
		args.must_eat = 0;
	if (check_args(ac, &args) != 0)
		return (0);
	return (&args);
}
