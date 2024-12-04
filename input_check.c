/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:49:34 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/04 14:17:00 by rshaheen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	input_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_digit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i])
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

bool	input_within_range(int argc, char **argv)
{
	
}

bool	input_check(int argc, char **argv)
{
	if (input_is_digit(argv[1]) == false || input_is_digit(argv[2]) == false
		|| input_is_digit(argv[3]) == false || input_is_digit(argv[4]) == false
		|| (argc == 6 && input_is_digit(argv[5]) == false))
		return (error_msg(2), false);
	if (input_within_range(argc, argv) == false)
		return (error_msg(2), false);
	return (true);
}