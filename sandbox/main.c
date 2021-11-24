#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define N 6
#define FREE 0
#define TAKEN 1
#define LEFTFORK(n) n
#define RIGHTFORK(n) (n + 1) % N
#define ISLEFT_FREE(n) forks[LEFTFORK(n)] == FREE
#define ISRIGHT_FREE(n) forks[RIGHTFORK(n)] == FREE

pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
int	forks[N];

typedef struct timeval t_timeval;
typedef struct timezone t_timezone;

void	*philosopher(int n)
{
	int			waiting;
	size_t		i;
	t_timeval	tv;
	t_timezone	tz;
	long		last_time;

	gettimeofday(&tv, &tz);
	last_time = tv.tv_usec;
	while (1)
	{
		waiting = 1;
		printf("[%d] THINKING\n", n);
		while (waiting)
		{
			gettimeofday(&tv, &tz);
			if (tv.tv_usec - last_time > 2 * 1000000)
			{
				printf("[%d] DIE AFTER [%llu]\n", n, tv.tv_usec - last_time);
				return (NULL);
			}
			else
				printf("last time %ld tv_usec %ld difference %ld\n", last_time, tv.tv_usec, tv.tv_usec - last_time);
			pthread_mutex_lock(&mutex);
			if (ISLEFT_FREE(n) && ISRIGHT_FREE(n))
			{
				forks[LEFTFORK(n)] = TAKEN;
				forks[RIGHTFORK(n)] = TAKEN;
				printf("[%d] TAKE FORK %d and %d\n",n,  LEFTFORK(n), RIGHTFORK(n));
				waiting = 0;
			}
			pthread_mutex_unlock(&mutex);
		}
		printf("\033[0;36m[%d] EATING\n\033[0m", n);
		sleep(2);
		pthread_mutex_lock(&mutex);
		printf("[%d] REALEASE FORKS %d and %d\n",n,  LEFTFORK(n), RIGHTFORK(n));
		forks[LEFTFORK(n)] = FREE;
		forks[RIGHTFORK(n)] = FREE;
		pthread_mutex_unlock(&mutex);
		printf("[%d] SLEEPING\n", n);
		sleep(2);
		gettimeofday(&tv, &tz);
		last_time = tv.tv_usec;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	threads[N];
	size_t		i;


	i = 0;
	while (i < N)
	{
		pthread_create(&threads[i], NULL, philosopher, (void *)i);
		i++;
	}
	i = 0;
	while (i < N)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return (0);
}