#include "philo.h"

void	*ph_print_died(t_phil *tmp)
{
	if (*(tmp->death) == 1)
	{
		pthread_mutex_unlock(tmp->mut);
		return (0);
	}
	*(tmp->death) = 1;
	printf("%8ld %3d died\n", ph_get_time() - tmp->start, tmp->phil);
	pthread_mutex_unlock(tmp->mut);
	return (0);
}

int	ph_print_status(t_phil *tmp, char *status)
{
	pthread_mutex_lock(tmp->mut);
	if (*(tmp->death) == 1)
	{
		pthread_mutex_unlock(tmp->mut);
		return (0);
	}
	printf("%8ld %3d %s\n", ph_get_time() - tmp->start, tmp->phil, status);
	pthread_mutex_unlock(tmp->mut);
	return (1);
}

int	ph_print_fork(t_phil *tmp)
{
	if (*(tmp->death) == 1)
	{
		pthread_mutex_unlock(tmp->mut);
		return (0);
	}
	printf("%8ld %3d has taken a fork\n", tmp->start_eat - tmp->start,
		tmp->phil);
	printf("%8ld %3d is eating\n", tmp->start_eat - tmp->start, tmp->phil);
	pthread_mutex_unlock(tmp->mut);
	return (1);
}
