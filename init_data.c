/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 18:55:04 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/16 16:46:43 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Mutexes prevent "data races", not deadlocks.like race for forks
//Mutexes ensure that the initialization and update of the variable/s
//being guarded are done safely without conflicts, like toilet locks
//here setting the attribute of mutex_init to NULL coz we want default
//is_alive_lock mutex: Guards 'is_alive" variable
//meal_lock mutex: Guards the num_of_meals and last_meal, 
// is_meal_count_input (indrectly)
//start_time_lock mutex:Guards start_time. 


int	init_mutex(t_data *data)
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
	if (pthread_mutex_init(&data->start_time_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->meal_lock);
		pthread_mutex_destroy(&data->is_alive_lock);
		write(2, "Error init mutex start_time_lock\n", 29);
		return (1);
	}
	return (0);
}


//Setting num_of_meals to -1 when the fifth argument is not provided.
//so that philosopher can eat indefinitely

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
		data.is_meal_count_input = true;
		data.meal_count_input = ft_atol(argv[5]);
	}
	else
	{
		data.is_meal_count_input = false;
		data.meal_count_input = -1;
	}
	init_mutex(&data);
	data.philo = NULL;
	return (data);
}
