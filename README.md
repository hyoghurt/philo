# philo
Задача об обедающих философах
[wikipedia](https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BE%D0%B1_%D0%BE%D0%B1%D0%B5%D0%B4%D0%B0%D1%8E%D1%89%D0%B8%D1%85_%D1%84%D0%B8%D0%BB%D0%BE%D1%81%D0%BE%D1%84%D0%B0%D1%85)

Сборка: `/philo/make`  
Запуск: `/philo/philo [arg1] [arg2] [arg3] [arg4] [arg5]`  
[arg1] - количество философов  
[arg2] - время(миллисекунды), если философ не начинает есть после его последнего приема пищи или начала симуляции, он умирает;  
[arg3] - время(миллисекунды), необходимое философу, чтобы поесть;  
[arg4] - время(миллисекунды), которое философ проведет во сне;  
[arg5] - аргумент является необязательным, если все философы съедают хотя бы [arg5], симуляция остановится. Если не указано иное, симуляция остановится только в случае смерти философа. 

Используемые функции:
```
memset, printf, malloc, free, write, usleep, gettimeofday
pthread_create, pthread_detach, pthread_join
pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
```
![terminal](https://github.com/hyoghurt/philo/raw/master/terminal.png)
