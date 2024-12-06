/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:49:34 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/06 19:18:14 by rshaheen      ########   odam.nl         */
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

bool	input_is_digit(char **array)
{
	int	i;
	int	j;

	i = 1;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (ft_is_digit(array[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int long	ft_atol(char *str)
{
	int			i;
	int long	n;

	i = 0;
	n = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

bool	input_within_range(char **argv)
{
	int	i;

	i = 2;
	if (ft_atol(argv[1]) < 1 || ft_atol(argv[1]) > 200)
		return (false);
	while (argv[i])
	{
		if (ft_atol(argv[i]) < 1 || ft_atol(argv[i]) > INT_MAX)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	input_checker(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_msg(1), false);
	if (input_is_digit(argv) == false)
		return (error_msg(2), false);
	if (input_within_range(argv) == false)
		return (error_msg(2), false);
	return (true);
}
