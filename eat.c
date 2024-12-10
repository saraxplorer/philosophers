/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 14:16:43 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/10 15:59:52 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_single_philo(t_philo *philo)//why static in dudas
{
	if (philo->data->number_of_philos == 1)
	{
		pthread_mutex_lock(&philo->data->meal_lock);//more about meal_lock
		philo->last_meal = get_current_time();// why it is needed?
		pthread_mutex_unlock(&philo->data->meal_lock);
		pthread_mutex_unlock(philo->right_fork);
		simulate_activity_duration(philo->data->time_to_die, philo);
		return (true);
	}
	return (false);
}

bool	lock_second_and_eat(t_philo *philo, pthread_mutex_t *second_fork)
{
	if (pthread_mutex_lock(second_fork) == 0)
	{
		print_msg(philo, PICK_FORK);
		print_msg(philo, EAT);
		pthread_mutex_lock(&philo->data->meal_lock);
		philo->last_meal = get_current_time();
		philo->num_of_meals += 1;
		pthread_mutex_unlock(&philo->data->meal_lock);
		simulate_activity_duration(philo->data->time_to_eat, philo);
		pthread_mutex_unlock(second_fork);
		return (true);
	}
	else
	{
		write(2, "Error locking second fork\n", 27);
		return (false);
	}
}

bool	lock_first_fork(t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)//why static
{
	if (pthread_mutex_lock(first_fork) == 0)
	{
		print_msg(philo, PICK_FORK);
		if (is_single_philo(philo) == true)
			return (false);
		lock_second_and_eat(philo, second_fork);
		pthread_mutex_unlock(first_fork);
		return (true);
	}
	else
	{
		write(2, "Error locking first fork\n", 26);
		return (false);
	}
}

bool	eat(t_philo *philo)//why not static here??
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->philo_id % 2 == 0)// why opposite here?why does it matter?
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	if (lock_first_fork(philo, first_fork, second_fork) == false)
		return (false);
	return (true);
}
