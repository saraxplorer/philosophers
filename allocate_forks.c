/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate_forks.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 21:37:10 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/06 21:47:04 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	allocate_forks(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(data->number_of_philos * sizeof(pthread_mutex_t));
	if (data->fork == NULL)
	{
		write(2, "Error in memory allocation for forks\n", 38);
		return (false);
	}
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			while (i > 0)
			{
				pthread_mutex_destroy(&data->fork[i]);
				write(2, "Error in mutex init for fork\n", 30);
				i--;
			}
			free (data->fork);
			return (false);
		}
		i++;
	}
	return (true);
}
