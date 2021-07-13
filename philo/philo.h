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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
	int				phil;
	int				*death;
	int				num;
	int				*arr_eat;
	int				*eat;
	int				n_must_eat;
	long			start;
	long			start_eat;
	long			t_die;
	long			t_eat;
	long			t_sleep;
}					t_phil;

//lib
long			ft_atoi_long(const char *nptr);
int				ft_isdigit(int c);
//init
int				ph_init(char **argv, t_phil **phil, pthread_mutex_t **fork);
pthread_mutex_t	*crt_mutex_arr(int num);
int				ph_init_hand(t_phil *phil, pthread_mutex_t *fork, int num);
int				ph_init_value(t_phil *phil, int num, char **argv);
int				ph_init_argv(t_phil *phil, int num, char **argv);
//init_2
int				ph_init_time(t_phil *phil, int num);
int				ph_init_print(t_phil *phil, int num);
int				ph_init_death(t_phil *phil, int num);
int				ph_init_eat(t_phil *phil, int num);
//check
int				ph_check_arg(int argc, char **argv);
int				ft_check_digit(char *s);
//add
long			ph_get_time(void);
void			ph_usleep_eat(t_phil *tmp);
void			ph_usleep_sleep(t_phil *tmp);
void			ph_free(t_phil *phil, pthread_mutex_t *fork);
//exec
void			*ft_phil(void *arg);
void			*ph_died(void *arg);
int				ph_print_status(t_phil *tmp, char *status);
//
void			*ph_check_num_eat(void *arg);
int				ret_error(void);

#endif
