#include "../includes/philosophers.h"

void	join_thread(void *v)
{
	t_philo	*philo;
	void	*ret;

	philo = (t_philo *)v;
	if (pthread_join(philo->thread, &ret) != 0)
	{
		printf("Unable to join thread.\n");
		return ;
	}
	printf("[%ld] %d died\n", timestamp(), philo->id);
}

void	join_threads(t_args *args)
{
	ft_lstiter(args->members, join_thread);
}

int	create_thread(t_philo *philo)
{
	pthread_attr_t	*params;
	void			*arg;

	params = NULL;
	arg = philo;
	if (pthread_create(&(philo->thread), params, start, arg) != 0)
	{
		printf("Unable to create thread.\n");
		return (1);
	}
	return (0);
}
