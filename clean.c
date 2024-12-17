/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 17:07:12 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/17 13:03:44 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (data->fork_locks != NULL)
	{
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->fork_locks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&data->is_alive_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->start_time_lock);
}

void	clean(t_data *data)
{
	destroy_mutex(data);
	if (data->fork_locks != NULL)
		free(data->fork_locks);
	if (data->philo != NULL)
		free(data->philo);
}
