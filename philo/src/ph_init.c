#include "philo.h"

int	ph_init(char **argv, t_phil **phil, pthread_mutex_t **fork)
{
	int				num;

	num = (int)ft_atoi_long(argv[1]);
	*phil = (t_phil *)malloc(num * sizeof(t_phil));
	if (!(*phil))
		return (0);
	*fork = crt_mutex_arr(num);
	if (!(*fork))
	{
		free(*phil);
		return (0);
	}
	ph_init_hand(*phil, *fork, num);
	if (!ph_init_value(*phil, num, argv))
	{
		free(*fork);
		free(*phil);
		return (0);
	}
	return (1);
}

pthread_mutex_t	*crt_mutex_arr(int num)
{
	pthread_mutex_t	*mut;
	int				i;

	mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!mut)
		return (0);
	i = -1;
	while (++i < num)
		pthread_mutex_init(&mut[i], 0);
	return (mut);
}

int	ph_init_hand(t_phil *phil, pthread_mutex_t *fork, int num)
{
	int		i;

	i = -1;
	while (++i < num)
	{
		if (i < num - 1)
		{
			phil[i].right_fork = &fork[i];
			phil[i].left_fork = &fork[i + 1];
		}
		else
		{
			phil[i].right_fork = &fork[i];
			phil[i].left_fork = &fork[0];
		}
	}
	return (1);
}

int	ph_init_value(t_phil *phil, int num, char **argv)
{
	ph_init_argv(phil, num, argv);
	if (!ph_init_print(phil, num))
		return (0);
	if (!ph_init_death(phil, num))
	{
		free(phil[0].print);
		return (0);
	}
	if (!ph_init_eat(phil, num))
	{
		free(phil[0].print);
		free(phil[0].death);
		return (0);
	}
	ph_init_time(phil, num);
	return (1);
}

int	ph_init_argv(t_phil *phil, int num, char **argv)
{
	long	t_die;
	long	t_eat;
	long	t_sleep;
	int		n_must_eat;
	int		i;

	n_must_eat = -1;
	t_die = ft_atoi_long(argv[2]);
	t_eat = ft_atoi_long(argv[3]);
	t_sleep = ft_atoi_long(argv[4]);
	if (argv[5])
		n_must_eat = (int)ft_atoi_long(argv[5]);
	i = -1;
	while (++i < num)
	{
		phil[i].phil = i + 1;
		phil[i].num = num;
		phil[i].t_die = t_die;
		phil[i].t_eat = t_eat;
		phil[i].t_sleep = t_sleep;
		phil[i].n_must_eat = n_must_eat;
	}
	return (1);
}
