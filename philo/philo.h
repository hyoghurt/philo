#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phil
{
	pthread_t		pthr;
	pthread_mutex_t	*mut;
	int				*fork;
	int				*arr_eat;
	int				*death;
	int				*small;
	int				*big;
	int				*eat;
	int				phil;
	int				num;
	long			start;
	long			start_eat;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				n_must_eat;
}					t_phil;

//lib
long	ft_atoi_long(const char *nptr);
int		ft_isdigit(int c);
//init
int		ph_init(char **argv, t_phil **phil);
int		ph_init_value(t_phil *phil, int num, char **argv);
int		ph_init_argv(t_phil *phil, int num, char **argv);
int		ph_init_hand(t_phil *phil, int num);
//init_2
int		ph_init_time(t_phil *phil, int num);
int		ph_init_mutex(t_phil *phil, int num);
int		ph_init_death(t_phil *phil, int num);
int		ph_init_fork_eat(t_phil *phil, int num);
//check
int		ph_check_arg(int argc, char **argv);
int		ft_check_digit(char *s);
//add
long	ph_get_time(void);
int		ret_null(t_phil *tmp);
void	ph_usleep(t_phil *tmp);
void	ph_free(t_phil *phil);
//print
void	*ph_print_died(t_phil *tmp);
int		ph_print_status(t_phil *tmp, char *status);
int		ph_print_fork(t_phil *tmp);
//exec
void	*ft_phil(void *arg);
int		ph_take_fork(t_phil *tmp);
int		ph_eating_and_sleeping(t_phil *tmp);
//exec_2
int		ph_eating(t_phil *tmp);
int		ph_sleeping(t_phil *tmp);
int		ph_num_eat(t_phil *tmp);

#endif
