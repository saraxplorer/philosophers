/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:00:02 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/04 13:49:18 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_msg(1), EXIT_FAILURE);
	if (input_check(argc, argv) == false)
		return (EXIT_FAILURE);
	
}
