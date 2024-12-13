/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:26:24 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/13 22:27:55 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_msg(int error_num)
{
	if (error_num == 1)
	{
		printf("Error: incorrect input!");
		printf("Enter:\n1. Number of philosophers (1-200)\n2. Time to die");
		printf("(ms)\n3. Time to eat(ms)\n4. Time to sleep(ms)\n5. ");
		printf("Number of times each phlosopher eats(optional)\n");
	}
	else if (error_num == 2)
	{
		printf("Error: Invalid argument input \n");
		error_msg(1);
	}
}

//1. How should the timestamp look like??
//2. timestamp shows 101 201 301 if data->philo[i].left_fork = &data->fork_locks[i + 1]. but gives 100 200 most times if it is [i - 1]

int long	time_stamp(t_data *data)
{
	long int	current_time;
	long int	new_time;

	current_time = get_current_time();
	new_time = current_time - data->start_time;
	return (new_time);
}

void	print_msg(t_philo *philo, int flag)
{
	int long	time;

	pthread_mutex_lock(&philo->data->is_alive_lock);//why??
	if (philo->data->is_alive == true)//why??
	{
		time = time_stamp(philo->data);
		if (flag == EAT)
			printf("%ld %d is eating\n", time, philo->philo_id);
		if (flag == SLEEP)
			printf("%ld %d is sleeping\n", time, philo->philo_id);	
		if (flag == THINK)
			printf("%ld %d is thinking\n", time, philo->philo_id);
		if (flag == PICK_FORK)
			printf("%ld %d has picked up a fork\n", time, philo->philo_id);
	}
	pthread_mutex_unlock(&philo->data->is_alive_lock);
}
