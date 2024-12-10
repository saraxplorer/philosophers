/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 13:29:13 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/10 16:12:59 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	stop_simulation(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->deadlock);//what is deadlock?
	if (philo->data->is_alive == false
		|| philo->num_of_meals == philo->data->num_of_meals)//???
	{
		pthread_mutex_unlock(&philo->data->deadlock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->deadlock);
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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->start_lock);
	pthread_mutex_unlock(&philo->data->start_lock);
	if ((philo->philo_id % 2) == 0)
	{
		print_msg(philo, THINK);
		simulate_activity_duration(philo->data->time_to_eat / 2, philo);
	}
	while (1)
	{
		if (eat(philo) == false)
			return (NULL);
		if (stop_simulation(philo) == true)
			return (NULL);
		sleep_and_think(philo);
	}
	return (NULL);
}
