#include "philo.h"

int	main(int argc, char **argv)
{
	pthread_t		pthr;
	pthread_t		n_eat;
	t_phil			*phil;
	pthread_mutex_t	*fork;
	int				i;

	if (ph_check_arg(argc, argv))
		return (ret_error());
	if (!ph_init(argv, &phil, &fork))
		return (ret_error());
	pthread_create(&n_eat, 0, ph_check_num_eat, &phil[0]);
	i = -1;
	while (++i < phil[0].num)
	{
		pthread_create(&pthr, 0, ft_phil, &phil[i]);
		usleep(100);
	}
	pthread_join(n_eat, 0);
	ph_free(phil, fork);
	return (0);
}

void	*ph_check_num_eat(void *arg)
{
	t_phil	*tmp;
	int		i;

	tmp = (t_phil *)arg;
	i = 0;
	if (tmp->n_must_eat >= 0)
	{
		while (i < tmp->num)
		{
			if (*(tmp->death) == 1)
				return (0);
			if (tmp->arr_eat[i] >= tmp->n_must_eat)
				i++;
		}
	}
	else
		while (*(tmp->death) == 0)
			usleep(300);
	return (0);
}

int	ret_error(void)
{
	printf("Error\n");
	return (1);
}
