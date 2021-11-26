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

t_philo	*right_fork(t_args *args, t_philo *philo)
{
	int	target_id;
	
	target_id = (philo->id % args->nb) + 1;
	return (get_philo(args, target_id));
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
}

void	release_fork(t_philo *philo)
{
	return (NULL);
}
*/