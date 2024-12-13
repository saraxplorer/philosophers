/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate_fork_lock.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 21:37:10 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/13 21:32:42 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//fork_locks is the COLLECTION of all locks for forks
//because it allocates for all fork mutexes "NUMBER OF PHILO/FORKS TIME"
//so it is an array of mutexes


bool	allocate_fork_lock(t_data *data)
{
	int	i;

	i = 0;
	data->fork_locks = malloc(data->number_of_philos * sizeof(pthread_mutex_t));
	if (data->fork_locks == NULL)
	{
		write(2, "Error in memory allocation for fork_lock\n", 42);
		return (false);
	}
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(&data->fork_locks[i], NULL) != 0)
		{
			while (i > 0)
			{
				pthread_mutex_destroy(&data->fork_locks[i]);
				write(2, "Error in mutex initialization for fork_lock\n", 45);
				i--;
			}
			free (data->fork_locks);
			return (false);
		}
		i++;
	}
	return (true);
}
