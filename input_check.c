/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:49:34 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/04 18:02:34 by rshaheen      ########   odam.nl         */
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

int long	ft_atol(char *str)
{
	int			i;
	int long	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

bool	input_within_range(int argc, char **argv)
{
	if (ft_atol(argv[1]) <= 0 || ft_atol(argv[1]) > MAX_PHILO
		|| ft_atol(argv[2]) < 0 || ft_atol(argv[2]) > INT_MAX
		|| ft_atol(argv[3]) < 0 || ft_atol(argv[3]) > INT_MAX
		|| ft_atol(argv[4]) < 0 || ft_atol(argv[4]) > INT_MAX)
		return (false);
	if (argc == 6)
	{
		if (ft_atol(argv[5]) < 0 || ft_atol(argv[5]) > INT_MAX)
			return (false);
	}
	return (true);
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