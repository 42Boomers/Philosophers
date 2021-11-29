#include "../includes/philosophers.h"

void	*start(void *arg)
{
	t_philo			*philo;
	int				waiting;
	unsigned long	msec;

	philo = (t_philo*) arg;
	msec = timestamp();
	if (msec == 0)
	{
		printf("Error\nUnable to get timestamp.\n");
		return (NULL);
	}
	philo->last_msec = msec;
	while (1)
	{
		waiting = 1;
		while (waiting)
		{
			//if (tv.tv_sec - philo->last_sec >= 4 && philo->last_usec - MARGIN_OF_ERROR > philo->last_usec)
			waiting = get_forks(philo);
			msec = timestamp();
			if ((int) msec - philo->last_msec >= philo->args->time_die)
			{
				//printf("[%ld] %d died after [%lds%ldu]\n", timestamp(), philo->id, tv.tv_sec - philo->last_sec, tv.tv_usec - philo->last_usec);
				philo->action = DEAD_ALONE;
				printf("[%ld] %d died\n", msec, philo->id);
				return (0);
			}
		}
		printf("\033[0;36m[%ld] %d is eating\n\033[0m", timestamp(), philo->id);
		usleep(philo->args->time_eat * 1000);
		release_forks(philo);
		philo->times_eat++;
		if (philo->args->must_eat != -1 && philo->times_eat >= philo->args->must_eat)
		{
			philo->action = END;
			return (0);
		}
		printf("[%ld] %d is sleeping\n", timestamp(), philo->id);
		usleep(philo->args->time_sleep * 1000);
		msec = timestamp();
		printf("[%ld] %d is thinking\n", msec, philo->id);
		philo->last_msec = msec;
	}
	return (0);
}
