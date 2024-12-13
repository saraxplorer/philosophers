/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate_philo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 21:49:31 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/13 21:50:25 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//philo is COLLECTION of structs which allocated
//NUMBER OF PHILO times
//It also acts like an array
//locking forks for every philo in every turn
//Each philosopher takes one fork corresponding to their ID
//For second fork, they take the fork corresponding to the next ID(i.e., ID + 1)
//except for the last philosopher who takes the first fork instead.
//for him, second fork will be the first fork
//This makes the table round

bool	allocate_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(data->number_of_philos * sizeof(t_philo));
	if (data->philo == NULL)
	{
		printf("memory allocation for philos failed\n");
		return (false);
	}
	while (i < data->number_of_philos)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].num_of_meals = 0;
		data->philo[i].last_meal = 0;
		data->philo[i].right_fork = &data->fork_locks[i];
		if (data->philo[i].philo_id == data->number_of_philos)
			data->philo[i].left_fork = &data->fork_locks[0];
		else
			data->philo[i].left_fork = &data->fork_locks[i + 1];
		data->philo[i].data = data;
		i++;
	}
	return (true);
}

