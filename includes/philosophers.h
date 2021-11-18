#ifndef PHILOSPHER.H
# define PHILOSPHER.H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_args
{
	int	*members;
	int	*time_die;
	int *time_eat;
	int *time_sleep;
	int *must_eat;
}	t_args;

int	*ft_atoi_ultimate(const char *str);

#endif