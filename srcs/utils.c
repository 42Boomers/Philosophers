#include "../includes/philosophers.h"
#include <limits.h>

unsigned long	timestamp()
{
	t_timeval		tv;
	t_timezone		tz;
	unsigned long	ts;

	if (gettimeofday(&tv, &tz))
	{
		return (0);
	}
	ts = tv.tv_usec / 1000;
	ts += tv.tv_sec * 1000;
	return (ts);
}
