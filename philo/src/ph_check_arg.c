#include "philo.h"

int	ph_check_arg(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
		return (1);
	i = 0;
	while (argv[++i])
	{
		if (ft_check_digit(argv[i]))
			return (1);
	}
	return (0);
}

int	ft_check_digit(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}
