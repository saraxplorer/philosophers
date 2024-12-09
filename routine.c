#include "philo.h"

//struct timeval is a structure in C used to represent time with microsecond precision. 
//It is commonly used in system programming for measuring time intervals or getting the current time. 
//The structure is defined in the <sys/time.h> header file.
//prototype == int gettimeofday(struct timeval *tv, struct timezone *tz);
//tv = time in seconds
//tz = timezone, almoat always NULL
//tv_sec is the number of seconds since the UNIX epoch (January 1, 1970).
//Multiplying it by 1000 converts seconds to milliseconds.
//tv_usec represents the additional microseconds (1 second = 1,000,000 microseconds).
//Dividing by 1000 converts microseconds to milliseconds.
int long    get_current_time(void)
{
    struct timeval  time;
    int long        time_milisec;

    if (gettimeofday(&time, NULL) != 0)
    {
        write(2, "error getting time\n", 20);//can use printf of print error???
        return (1);//why 0 in dudas??
    }
    time_milisec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (time_milisec);
}



int long    time_stamp(t_data *data)//why long????
{
    long int    current_time;
    long int    new_time;

    current_time = get_current_time();
    new_time = current_time - data->start_time;
    return (new_time);
}


void    print_msg(t_philo *philo, int flag)
{
    int long    time;

    pthread_mutex_lock(&philo->data->deadlock);//why??
    if (philo->data->is_alive == true)//why??
    {
        time = time_stamp(philo->data);
        if (flag == EAT)
            printf("%ld: %ld is eating\n", time, philo->philo_id);
        if (flag == SLEEP)
            printf("%ld: %ld is sleeping\n", time, philo->philo_id);
        if (flag == THINK)
            printf("%ld: %ld is thinking\n", time, philo->philo_id);
        if (flag == PICK_FORK)
            printf("%ld: %ld has picked up a fork\n", time, philo->philo_id);
    }
    pthread_mutex_unlock(&philo->data->deadlock);
}

void    rest(int long waiting_time, t_philo *philo)
{
    int long    wakeup_time;

    wakeup_time = get_current_time() + waiting_time;
    while (wakeup_time > get_current_time())
    {
        usleep(100);
        
    }
}


void    *routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    pthread_mutex_lock(&philo->data->start_lock);
    pthread_mutex_unlock(&philo->data->start_lock);
    if ((philo->philo_id % 2) == 0)
    {
        print_msg(philo, THINK);
        rest(philo->data->time_to_eat / 2, philo);
    }
}