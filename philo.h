/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshaheen <rshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:00:43 by rshaheen          #+#    #+#             */
/*   Updated: 2024/12/06 22:14:26 by rshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

# define MAX_PHILO 200

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	int long		start_time;
	bool			is_alive;
	bool			has_meal;
	t_philo			*philo;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	deadlock;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	*fork;

}	t_data;

typedef struct s_philo
{
	int				philo_id;
	int				num_of_meals;
	int				last_meal;
	t_data 			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int long	ft_atol(char *str);
bool		input_checker(int argc, char **argv);
void		error_msg(int error_num);

t_data		init_data(int argc, char **argv);
bool		allocate_forks(t_data *data);
bool		allocate_philo(t_data *data);

#endif