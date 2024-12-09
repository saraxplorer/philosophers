/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_thread.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 22:17:24 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/10 16:43:24 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	make_thread(t_data *data)//what is the use of table_id??
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->start_lock);
	while (i < data->number_of_philos)
	{
		if (pthread_create(&data->philo[i].table_id, NULL,
				&routine, &data->philo[i]) != 0)
		{
			pthread_mutex_unlock(&data->start_lock);
			write(2, "Error making thread\n", 21);
			return (i);
		}
		i++;
	}
	data->start_time = get_current_time();
	pthread_mutex_unlock(&data->start_lock);
	return (i);
}
