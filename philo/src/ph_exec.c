#include "philo.h"

void	*ft_phil(void *arg)
{
	t_phil			*tmp;
	pthread_t		pthr;

	tmp = (t_phil *)arg;
	pthread_create(&pthr, 0, ph_died, tmp);
	while (1)
	{
		ph_print_status(tmp, "is thinking");
		pthread_mutex_lock(tmp->right_fork);
		pthread_mutex_lock(tmp->left_fork);
		ph_print_status(tmp, "has taken a fork");
		tmp->start_eat = ph_get_time();
		ph_print_status(tmp, "is eating");
		ph_usleep_eat(tmp);
		*tmp->eat = *tmp->eat + 1;
		pthread_mutex_unlock(tmp->left_fork);
		pthread_mutex_unlock(tmp->right_fork);
		ph_print_status(tmp, "is sleeping");
		ph_usleep_sleep(tmp);
	}
	return (0);
}

void	*ph_died(void *arg)
{
	t_phil			*tmp;

	tmp = (t_phil *)arg;
	while (1)
	{
		if (*(tmp->death) == 1)
			return (0);
		if (tmp->t_die < (ph_get_time() - tmp->start_eat))
		{
			if (*(tmp->death) == 1)
				return (0);
			pthread_mutex_lock(tmp->print);
			*(tmp->death) = 1;
			printf("%8ld %3d died\n", ph_get_time() - tmp->start, tmp->phil);
			return (0);
		}
		usleep(300);
	}
	return (0);
}

int	ph_print_status(t_phil *tmp, char *status)
{
	pthread_mutex_lock(tmp->print);
	printf("%8ld %3d %s\n", ph_get_time() - tmp->start, tmp->phil, status);
	pthread_mutex_unlock(tmp->print);
	return (1);
}
