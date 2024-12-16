/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:41:44 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/16 15:23:27 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	to_stop_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->is_alive_lock);
	if (philo->data->is_alive == false
		|| philo->num_of_meals == philo->data->meal_count_input)
	{
		pthread_mutex_unlock(&philo->data->is_alive_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->is_alive_lock);
	return (false);
}

void	sleep_and_think(t_philo *philo)
{
	int long	thinking_time;

	thinking_time = 2 * philo->data->time_to_eat - philo->data->time_to_sleep;
	if (thinking_time < 0)
		thinking_time = 0;
	print_msg(philo, SLEEP);
	simulate_activity_duration(philo->data->time_to_sleep, philo);
	print_msg(philo, THINK);
	if (philo->data->number_of_philos % 2 != 0)
		simulate_activity_duration(thinking_time, philo);
}
//If the philosopher has an even ID, he eats for half the time 
//(philo->data->time_to_eat / 2) and then switch to sleeping/thinking.

//lock and unlock keeps timestamp consistent, 
//without it garbage valuse keeps coming in timestamp

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->start_time_lock);
	pthread_mutex_unlock(&philo->data->start_time_lock);
	if ((philo->philo_id % 2) == 0)
	{
		print_msg(philo, THINK);
		simulate_activity_duration(philo->data->time_to_eat / 2, philo);
	}
	while (1)
	{
		if (eat(philo) == false)
			return (NULL);
		if (to_stop_simulation(philo) == true)
			return (NULL);
		sleep_and_think(philo);
	}
	return (NULL);
}

//The 'main' thread is running when main() is called.
//The new thread is created using pthread_create and runs concurrently.

//Locking start_time_lock prevents any premature access to start_time, 
//ensuring it's safely accessed once all threads are created.

//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//void *(*start_routine)(void *), void *arg);
//thread: Pointer to the thread ID that will be set when thread is created.
//attr: Optional thread attributes, typically NULL for default
//start_routine: The function to be executed by the thread.
//arg: Argument passed to start_routine.

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->start_time_lock);
	while (i < data->number_of_philos)
	{
		if (pthread_create(&data->philo[i].thread_id, NULL,
				&routine, &data->philo[i]) != 0)
		{
			pthread_mutex_unlock(&data->start_time_lock);
			write(2, "Error making thread\n", 21);
			return (i);
		}
		i++;
	}
	data->start_time = get_current_time();
	pthread_mutex_unlock(&data->start_time_lock);
	return (i);
}
