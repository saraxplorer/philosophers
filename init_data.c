/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 18:55:04 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/13 22:14:39 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//setting the attribute of mutex_init to NULL coz we want default
//is_alive_lock mutex: Guards 'is_alive" variable
//Prevents race conditions when checking or updating is_alive
//meal_lock mutex: Guards the num_of_meals and has_meal.
//start_lock mutex:Guards the shared variable start_time.
//Ensures that the initialization and update of the start time of the simulation are done safely without conflicts.


int	init_mutex(t_data *data)//what do the locks represent??
{
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
	{
		write(2, "Error init mutex Meal Counter\n", 31);
		return (1);
	}
	if (pthread_mutex_init(&data->is_alive_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->meal_lock);
		write(2, "Error init mutex is_alive_lock\n", 27);
		return (1);
	}
	if (pthread_mutex_init(&data->start_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->meal_lock);
		pthread_mutex_destroy(&data->is_alive_lock);
		write(2, "Error init mutex start_lock\n", 29);
		return (1);
	}
	return (0);
}


t_data	init_data(int argc, char **argv)
{
	t_data	data;

	data.start_time = 0;
	data.is_alive = true;
	data.number_of_philos = ft_atol(argv[1]);
	data.time_to_die = ft_atol(argv[2]);
	data.time_to_eat = ft_atol(argv[3]);
	data.time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
	{
		data.has_meal = true;
		data.num_of_meals = ft_atol(argv[5]);
	}
	else
	{
		data.has_meal = false;
		data.num_of_meals = -1;
	}
	init_mutex(&data);
	data.philo = NULL;
	return (data);
}
