#include "philo.h"

int	ph_init_time(t_phil *phil, int num)
{
	struct timeval	time;
	int				i;

	if (gettimeofday(&time, 0) != 0)
		return (0);
	i = -1;
	while (++i < num)
	{
		phil[i].start = ((time.tv_sec % 1000) * 1000) + time.tv_usec / 1000;
		phil[i].start_eat = phil[i].start;
	}
	return (1);
}

int	ph_init_mutex(t_phil *phil, int num)
{
	pthread_mutex_t	*mut;
	int				i;

	mut = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!mut)
		return (0);
	if (pthread_mutex_init(mut, 0) != 0)
	{
		free(mut);
		return (0);
	}
	i = -1;
	while (++i < num)
		phil[i].mut = mut;
	return (1);
}

int	ph_init_death(t_phil *phil, int num)
{
	int				i;
	int				*death;

	death = (int *)malloc(sizeof(int));
	if (!death)
		return (0);
	*death = 0;
	i = -1;
	while (++i < num)
		phil[i].death = death;
	return (1);
}

int	ph_init_fork_eat(t_phil *phil, int num)
{
	int				i;
	int				*fork;
	int				*eat;

	fork = (int *)malloc(num * sizeof(int));
	if (!fork)
		return (0);
	eat = (int *)malloc(num * sizeof(int));
	if (!eat)
	{
		free(fork);
		return (0);
	}
	memset(fork, 1, num * sizeof(int));
	memset(eat, 0, num * sizeof(int));
	i = -1;
	while (++i < num)
	{
		phil[i].fork = fork;
		phil[i].arr_eat = eat;
		phil[i].eat = &phil[i].arr_eat[i];
	}
	return (1);
}
