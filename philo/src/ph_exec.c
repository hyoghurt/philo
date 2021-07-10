#include "philo.h"

void	*ft_phil(void *arg)
{
	t_phil	*tmp;
	int		flag;

	tmp = (t_phil *)arg;
	flag = 1;
	while (flag)
	{
		while (flag)
		{
			pthread_mutex_lock(tmp->mut);
			if (tmp->t_die < (ph_get_time() - tmp->start_eat))
				return (ph_print_died(tmp));
			pthread_mutex_unlock(tmp->mut);
			flag = ph_take_fork(tmp);
			usleep(400);
		}
		flag = ph_eating_and_sleeping(tmp);
	}
	return (0);
}

int	ph_take_fork(t_phil *tmp)
{
	pthread_mutex_lock(tmp->mut);
	if (*tmp->small)
	{
		*tmp->small = 0;
		if (*tmp->big)
		{
			*tmp->big = 0;
			tmp->start_eat = ph_get_time();
			if (!ph_print_fork(tmp))
				return (1);
			return (0);
		}
		else
			*tmp->small = 1;
	}
	pthread_mutex_unlock(tmp->mut);
	return (1);
}

int	ph_eating_and_sleeping(t_phil *tmp)
{
	if (!ph_eating(tmp))
		return (0);
	if (tmp->n_must_eat > 0 && ph_num_eat(tmp))
		return (0);
	if (!ph_sleeping(tmp))
		return (0);
	if (!ph_print_status(tmp, "is thinking"))
		return (0);
	usleep(100);
	return (1);
}
