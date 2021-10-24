# Philosophers
The dining philosophers problem 
[wikipedia](https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BE%D0%B1_%D0%BE%D0%B1%D0%B5%D0%B4%D0%B0%D1%8E%D1%89%D0%B8%D1%85_%D1%84%D0%B8%D0%BB%D0%BE%D1%81%D0%BE%D1%84%D0%B0%D1%85)

Compile: `./philo/make`  
Run: `./philo/philo [arg1] [arg2] [arg3] [arg4] [arg5]`  

[arg1] - is the number of philosophers and also the number of forks.  
[arg2] - is in milliseconds, if a philosopher doesn’t start eating [arg2] milliseconds after starting his last meal or the beginning of the simulation, it dies.  
[arg3] - is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.  
[arg4] - is in milliseconds and is the time the philosopher will spend sleeping.  
[arg5] - argument is optional, if all philosophers eat at least [arg5] the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.  

### Functions used:
```
memset, printf, malloc, free, write, usleep, gettimeofday
pthread_create, pthread_detach, pthread_join
pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
```
![terminal](https://github.com/hyoghurt/philo/raw/master/terminal.png)
