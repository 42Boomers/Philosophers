#include "../../includes/philosophers.h"

int	add_philo(t_args *args, int id)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	philo->id = id;
	philo->args = args;
	philo->times_eat = 0;
	philo->action = ALIVE;
	ft_lstadd_back(&(args->members), ft_lstnew(philo));
	create_thread(philo);
	return (0);
}

int	init_philo(t_args *args)
{
	int	i;

	i = 0;
	while (args->nb > i)
		add_philo(args, ++i);
	return (0);
}
