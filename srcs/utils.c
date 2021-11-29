#include "../includes/philosophers.h"

unsigned long	timestamp()
{
	t_timeval		tv;
	t_timezone		tz;
	unsigned long	ts;

	gettimeofday(&tv, &tz);
	ts = tv.tv_usec / 1000;
	ts += tv.tv_sec * 1000;
	return (ts);
}