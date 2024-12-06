/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   allocate_philo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 21:49:31 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/06 22:13:49 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		data->philo[i].right_fork = &data->fork[i];
		if (data->philo[i].philo_id == data->number_of_philos)
			data->philo[i].left_fork = &data->fork[0];
		else
			data->philo[i].left_fork = &data->fork[i + 1];
		data->philo[i].data = data;
		i++;
	}
	return (true);
}

