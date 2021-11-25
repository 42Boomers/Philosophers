#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define N 5
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

	long		last_usecond;
	long		last_second;

	gettimeofday(&tv, &tz);
	last_usecond = tv.tv_usec;
	last_second = tv.tv_sec;
	while (1)
	{
		waiting = 1;
		printf("[%d] THINKING\n", n);
		while (waiting)
		{
			gettimeofday(&tv, &tz);
			if (tv.tv_sec - last_second >= 4 && tv.tv_usec - (10000) > last_usecond)
			{
				printf("[%d] DIE AFTER [%lds%ldu]\n", n, tv.tv_sec - last_second, tv.tv_usec - last_usecond);
				exit(0);
			}
			// else
				// printf("last time %ld tv_usec %ld difference %ldu%ld\n", last_second, tv.tv_sec, tv.tv_sec - last_second, tv.tv_usec - last_usecond);
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
		usleep(2000000);
		pthread_mutex_lock(&mutex);
		printf("[%d] REALEASE FORKS %d and %d\n",n,  LEFTFORK(n), RIGHTFORK(n));
		forks[LEFTFORK(n)] = FREE;
		forks[RIGHTFORK(n)] = FREE;
		pthread_mutex_unlock(&mutex);
		printf("[%d] SLEEPING\n", n);
		usleep(2000000);
		gettimeofday(&tv, &tz);
		last_second= tv.tv_sec;
		last_usecond = tv.tv_usec;
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