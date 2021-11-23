#include "../includes/philosophers.h"

int	init_philo(t_list **list)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	philo->action = WAIT;
	ft_lstadd_back(list, ft_lstnew(philo));
	return (0);
}

void	*test(void	*arg)
{
	struct timeval	tv;
	struct timezone tz;

	gettimeofday(&tv, &tz);
	printf("Timestamp %ld\n", tv.tv_sec);
	printf("HELLO THREAD\n");
	printf("WHO ARE YOU ?\n");
	(void)arg;
	return (NULL);
}

int	create_thread()
{
	pthread_t 		thread;
	pthread_attr_t	*params;
	void			*arg;
  	void			*ret;
	
	params = NULL;
	arg = NULL;
	if (pthread_create(&thread, params, test, arg) != 0)
	{
		printf("Unable to create thread.\n");
		return (1);
	}
	//pthread_detach(thread);
	if (pthread_join(thread, &ret) != 0)
	{
		printf("Unable to join thread.\n");
		return (3);
	}
	printf("thread exited with '%s'\n", (char *)ret);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	/*
	if (args(ac, av) != 0)
		return (1);
	*/
	create_thread();
	printf("END\n");
	return (0);
}
