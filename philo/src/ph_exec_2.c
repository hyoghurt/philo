#include "philo.h"

int	ph_eating(t_phil *tmp)
{
	ph_usleep(tmp);
	pthread_mutex_lock(tmp->mut);
	*tmp->big = 1;
	pthread_mutex_unlock(tmp->mut);
	pthread_mutex_lock(tmp->mut);
	*tmp->small = 1;
	pthread_mutex_unlock(tmp->mut);
	return (1);
}

int	ph_sleeping(t_phil *tmp)
{
	if (!ph_print_status(tmp, "is sleeping"))
		return (0);
	if (tmp->t_eat + tmp->t_sleep > tmp->t_die)
	{
		usleep((tmp->t_die + tmp->start - ph_get_time()) * 1000);
		pthread_mutex_lock(tmp->mut);
		if (*(tmp->death) == 1)
			return (ret_null(tmp));
		*(tmp->death) = 1;
		printf("%8ld %3d died\n", ph_get_time() - tmp->start, tmp->phil);
		pthread_mutex_unlock(tmp->mut);
		return (0);
	}
	usleep((tmp->t_eat + tmp->t_sleep + tmp->start_eat - ph_get_time()) * 1000);
	return (1);
}

int	ph_num_eat(t_phil *tmp)
{
	int		num_eat;
	int		num;
	int		i;

	num_eat = tmp->n_must_eat;
	num = tmp->num;
	i = -1;
	pthread_mutex_lock(tmp->mut);
	*tmp->eat = *tmp->eat + 1;
	while (++i < num)
	{
		if (tmp->arr_eat[i] < num_eat)
			return (ret_null(tmp));
	}
	*(tmp->death) = 1;
	pthread_mutex_unlock(tmp->mut);
	return (1);
}
