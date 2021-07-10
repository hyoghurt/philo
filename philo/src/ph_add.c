#include "philo.h"

long	ph_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return ((time.tv_sec % 1000) * 1000 + time.tv_usec / 1000);
}

int	ret_null(t_phil *tmp)
{
	pthread_mutex_unlock(tmp->mut);
	return (0);
}

void	ph_usleep(t_phil *tmp)
{
	while (tmp->t_eat > (ph_get_time() - tmp->start_eat))
		usleep(300);
}

void	ph_free(t_phil *phil)
{
	pthread_mutex_destroy(phil->mut);
	free(phil->mut);
	free(phil->eat);
	free(phil->fork);
	free(phil->death);
	free(phil);
}
