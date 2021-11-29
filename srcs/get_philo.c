#include "../includes/philosophers.h"

t_philo	*get_philo(t_args *args, int id)
{
	int		i;
	t_list	*list;

	list = args->members;
	i = 0;
	while (list)
	{
		if (++i == id)
		{
			return ((t_philo *)list->content);
		}
		list = list->next;
	}
	return (NULL);
}

int	get_forks(t_philo *philo)
{
	t_args	*args;
	int		target_id;

	args = philo->args;
	target_id = (philo->id % args->nb);
	if (args->forks[target_id] == TAKEN || args->forks[philo->id - 1] == TAKEN)
		return (1);
	printf("[%ld] %d has taken fork %d\n", timestamp(), philo->id, target_id + 1);
	args->forks[philo->id - 1] = TAKEN;
	args->forks[target_id] = TAKEN;
	return (0);
}

void	release_forks(t_philo *philo)
{
	t_args	*args;
	int		target_id;

	args = philo->args;
	target_id = (philo->id % args->nb);
	if (args->forks[target_id] == FREE || args->forks[philo->id - 1] == FREE)
		return ;
	//printf("[%ld] %d REALEASE FORKS %d and %d\n", timestamp(), philo->id, philo->id, target_id + 1);
	args->forks[philo->id - 1] = FREE;
	args->forks[target_id] = FREE;
}

/*
int	get_fork(t_args *args, t_philo *philo)
{
	int		i;
	t_philo	*temp;
	t_list	*list;

	temp = NULL;
	list = args->members;
	i = 0;
	while (list)
	{
		if (++i == philo->id + 1 || (philo->id == args->nb && i == 1))
		{
			temp = (t_philo *)list->content;
		}
		list = list->next;
	}
	if (!temp || temp->fork < 1)
		return (-1);
	temp->fork = 0;
	philo->fork = 1;
	return (0);
}*/
