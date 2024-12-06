/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshaheen <rshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:17:24 by rshaheen          #+#    #+#             */
/*   Updated: 2024/12/06 22:20:10 by rshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	make_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->start_lock);
	while (i < data->number_of_philos)
	{
		if (pthread_create(&data->philo[i].))
		i++;
	}
}