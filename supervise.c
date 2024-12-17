/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   supervise.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 16:44:28 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/17 13:14:39 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// determines how much time has passed since the philosopher's last meal.
// by (get_current_time() - data->philo[i].last_meal)
// If THE TIME SINCE LAST MEAL exceeds time_to_die, updates is_alive to false
// Prints death message and returns true if a philosopher has died

bool	is_dead(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->is_alive_lock);
	pthread_mutex_lock(&data->meal_lock);
	while (i < data->number_of_philos)
	{
		if (data->philo[i].last_meal != 0 && get_current_time()
			- data->philo[i].last_meal > data->time_to_die)
		{
			data->is_alive = false;
			printf("%ld %d died\n", get_current_time() - data->start_time,
				data->philo[i].philo_id);
			pthread_mutex_unlock(&data->meal_lock);
			pthread_mutex_unlock(&data->is_alive_lock);
			return (true);
		}
		i++;
	}
	pthread_mutex_unlock(&data->meal_lock);
	pthread_mutex_unlock(&data->is_alive_lock);
	return (false);
}

bool	had_all_meals(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->meal_lock);
	if (data->is_meal_count_input == true)
	{
		while (i < data->number_of_philos)
		{
			if (data->philo[i].num_of_meals == data->meal_count_input)
			{
				pthread_mutex_unlock(&data->meal_lock);
				return (true);
			}
			i++;
		}
	}
	pthread_mutex_unlock(&data->meal_lock);
	return (false);
}

void	*supervise(t_data *data)
{
	while (1)
	{
		if (is_dead(data) == true || had_all_meals(data) == true)
			return (NULL);
		usleep(50);
	}
	return (NULL);
}
