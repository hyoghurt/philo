#include "philo.h"

int	ph_init_time(t_phil *phil, int num)
{
	struct timeval	time;
	int				i;

	gettimeofday(&time, 0);
	i = -1;
	while (++i < num)
	{
		phil[i].start = time.tv_sec * 1000 + time.tv_usec / 1000;
		phil[i].start_eat = phil[i].start;
	}
	return (1);
}

int	ph_init_print(t_phil *phil, int num)
{
	pthread_mutex_t	print;
	int				i;

	if (pthread_mutex_init(&print, 0) != 0)
		return (0);
	i = -1;
	while (++i < num)
		phil[i].print = &print;
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

int	ph_init_eat(t_phil *phil, int num)
{
	int				i;
	int				*eat;

	eat = (int *)malloc(num * sizeof(int));
	if (!eat)
		return (0);
	memset(eat, 0, num * sizeof(int));
	i = -1;
	while (++i < num)
	{
		phil[i].arr_eat = eat;
		phil[i].eat = &phil[i].arr_eat[i];
	}
	return (1);
}
