#include "philo.h"

void	myusleep(uint64_t tm)
{
	const uint64_t	curtm = get_time();

	while (get_time() - curtm < tm)
		usleep(1);
}
