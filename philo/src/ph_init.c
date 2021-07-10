#include "philo.h"

int	ph_init(char **argv, t_phil **phil)
{
	int	num;

	num = (int)ft_atoi_long(argv[1]);
	*phil = (t_phil *)malloc((num + 1) * sizeof(t_phil));
	if (!(*phil))
		return (0);
	if (!ph_init_value(*phil, num, argv))
	{
		free(*phil);
		return (0);
	}
	return (1);
}

int	ph_init_value(t_phil *phil, int num, char **argv)
{
	ph_init_argv(phil, num, argv);
	if (!ph_init_mutex(phil, num))
		return (0);
	if (!ph_init_death(phil, num))
	{
		free(phil[0].mut);
		return (0);
	}
	if (!ph_init_fork_eat(phil, num))
	{
		free(phil[0].death);
		free(phil[0].mut);
		return (0);
	}
	ph_init_hand(phil, num);
	if (!ph_init_time(phil, num))
	{
		free(phil[0].fork);
		free(phil[0].eat);
		free(phil[0].death);
		free(phil[0].mut);
		return (0);
	}
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

int	ph_init_hand(t_phil *phil, int num)
{
	int				i;

	i = -1;
	while (++i < num)
	{
		if (i < num - 1)
		{
			phil[i].small = &phil[i].fork[i];
			phil[i].big = &phil[i].fork[i + 1];
		}
		else
		{
			phil[i].small = &phil[i].fork[i];
			phil[i].big = &phil[i].fork[0];
		}
	}
	return (1);
}
