#include "philo.h"

long	ph_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ph_usleep_eat(t_phil *tmp)
{
	while (tmp->t_eat > (ph_get_time() - tmp->start_eat))
		usleep(300);
}

void	ph_usleep_sleep(t_phil *tmp)
{
	while (tmp->t_eat + tmp->t_sleep > (ph_get_time() - tmp->start_eat))
		usleep(300);
}

void	ph_free(t_phil *phil, pthread_mutex_t *fork)
{
	int	i;

	i = -1;
	while (++i < phil[0].num)
		pthread_mutex_destroy(&fork[i]);
	free(phil[0].eat);
	free(phil[0].death);
	free(fork);
	pthread_mutex_destroy(phil[0].print);
	free(phil[0].print);
	free(phil);
}
