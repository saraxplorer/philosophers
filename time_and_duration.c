/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_and_duration.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 17:16:34 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/16 14:52:38 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//struct timeval is a struct from <sys/time.h>used to show time  in microsecond
//prototype: int gettimeofday(struct timeval *tv, struct timezone *tz);
//tv = time in seconds
//tz = timezone, almost always NULL
//tv_sec is the number of seconds since the UNIX epoch (January 1, 1970).
//Multiplying it by 1000 converts seconds to milliseconds.
//tv_usec is the additional microseconds (1 second = 1,000,000 microseconds).
//Dividing by 1000 converts microseconds to milliseconds.

int long	get_current_time(void)
{
	struct timeval	time;
	int long		time_milisec;

	if (gettimeofday(&time, NULL) != 0)
	{
		write(2, "error getting time\n", 20);
		return (1);
	}
	time_milisec = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_milisec);
}

//usleep(100) pauses the thread for 100 microseconds/0.1 milliseconds at a time.
//It reduces CPU usage while allowing the thread to remain responsive.

void	simulate_activity_duration(int long waiting_time, t_philo *philo)
{
	int long	wakeup_time;

	wakeup_time = get_current_time() + waiting_time;
	while (wakeup_time > get_current_time())
	{
		usleep(100);
		pthread_mutex_lock(&philo->data->is_alive_lock);
		if (philo->data->is_alive == false)
		{
			pthread_mutex_unlock(&philo->data->is_alive_lock);
			return ;
		}
		pthread_mutex_unlock(&philo->data->is_alive_lock);
	}
}

