/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:26:24 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/04 14:01:52 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_msg(int error_num)
{
	if (error_num == 1)
	{
		printf("Enter:\n1. Number of philosophers (1-200)\n2. Time to die");
		printf("(ms)\n3. Time to eat(ms)\n4. Time to sleep(ms)\n5");
		printf("Number of times each phlosopher eats(optional)\n");
	}
	else if (error_num == 2)
	{
		printf("Error: Invalid argument input \n");
		error_msg(1);
	}
}
