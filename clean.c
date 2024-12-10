/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 17:07:12 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/10 17:18:58 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (data->fork != NULL)
	{
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->fork[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&data->deadlock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->start_lock);
}

void	clean(t_data *data)
{
	destroy_mutex(data);
	if (data->fork != NULL)
		free(data->fork);
	if (data->philo != NULL)
		free(data->philo);
}
