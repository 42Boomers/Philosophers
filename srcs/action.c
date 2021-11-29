#include "../includes/philosophers.h"

#define MARGIN_OF_ERROR 9000

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*start(void *arg)
{
	t_philo		*philo;
	int			waiting;
	t_timeval	tv;
	t_timezone	tz;

	philo = (t_philo*) arg;
	gettimeofday(&tv, &tz);
	philo->last_usec = tv.tv_usec;
	philo->last_sec = tv.tv_sec;
	while (1)
	{
		waiting = 1;
		while (waiting)
		{
			gettimeofday(&tv, &tz);
			if (tv.tv_sec - philo->last_sec >= 4 && philo->last_usec - MARGIN_OF_ERROR > philo->last_usec)
			{
				//printf("[%ld] %d died after [%lds%ldu]\n", timestamp(), philo->id, tv.tv_sec - philo->last_sec, tv.tv_usec - philo->last_usec);
				return (0);
			}
			pthread_mutex_lock(&g_mutex);
			waiting = get_forks(philo);
			pthread_mutex_unlock(&g_mutex);
		}
		printf("\033[0;36m[%ld] %d is eating\n\033[0m", timestamp(), philo->id);
		usleep(philo->args->time_eat * 1000);
		pthread_mutex_lock(&g_mutex);
		release_forks(philo);
		pthread_mutex_unlock(&g_mutex);
		philo->times_eat++;
		if (philo->args->must_eat != -1 && philo->times_eat >= philo->args->must_eat)
			return (0);
		printf("[%ld] %d is sleeping\n", timestamp(), philo->id);
		usleep(philo->args->time_sleep * 1000);
		printf("[%ld] %d is thinking\n", timestamp(), philo->id);
		gettimeofday(&tv, &tz);
		philo->last_sec = tv.tv_sec;
		philo->last_usec = tv.tv_usec;
	}
	return (0);
}
