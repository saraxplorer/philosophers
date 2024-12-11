/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshaheen <rshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:00:02 by rshaheen          #+#    #+#             */
/*   Updated: 2024/12/10 17:09:44 by rshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_threads(t_data *data, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (pthread_join(data->philo[i].table_id, NULL) != 0)
		{
			write(2, "Error in waiting for Philo thread to end\n", 42);
			return ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (input_checker(argc, argv) == false)
		return (EXIT_FAILURE);
	data = init_data(argc, argv);
	if (allocate_forks(&data) == false)
		return (EXIT_FAILURE);
	if (allocate_philo(&data) == false)
	{
		free(data.fork);
		return (EXIT_FAILURE);
	}
	i = make_thread(&data);
	supervise(&data);
	wait_for_threads(&data, i);
	clean(&data);
	return (0);
}

