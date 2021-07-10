#include "philo.h"

int	main(int argc, char **argv)
{
	t_phil			*phil;
	int				i;

	if (ph_check_arg(argc, argv))
	{
		printf("Error\n");
		return (0);
	}
	if (!ph_init(argv, &phil))
		return (0);
	i = -1;
	while (++i < phil[0].num)
	{
		printf("%8ld %3d is thinking\n", ph_get_time() - phil[i].start,
			phil[i].phil);
		pthread_create(&phil[i].pthr, 0, ft_phil, &phil[i]);
	}
	i = -1;
	while (++i < phil[0].num)
		pthread_join(phil[i].pthr, 0);
	ph_free(phil);
	return (0);
}
