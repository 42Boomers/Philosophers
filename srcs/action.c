#include "../includes/philosophers.h"

// DEPRECATED

long	get_time(t_args *args)
{
	struct timeval	tv;
	struct timezone	tz;

	gettimeofday(&tv, &tz);
	return (tv.tv_usec - args->start_time);
}

void	*eat(t_philo *philo)
{
	//pthread_mutex_lock(&g_mutex);
	philo->action = EAT;
	printf("%ld Philosopher %d is eating\n", get_time(philo->args), philo->id);
	usleep(500000);
	//test(philo);
	//pthread_mutex_unlock(&g_mutex);
	pthread_exit(0);
	return (NULL);
}

void	*start(void *v)
{
	t_philo			*philo;

	philo = (t_philo *)v;
	printf("%ld New Philosopher %d\n", get_time(philo->args), philo->id);
	usleep(500000);
	//pthread_mutex_unlock(&g_mutex);
	eat(philo);
	return (NULL);
}
