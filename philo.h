/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rshaheen <rshaheen@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:00:43 by rshaheen      #+#    #+#                 */
/*   Updated: 2024/12/17 13:48:08 by rshaheen      ########   odam.nl         */
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
# define EAT 1
# define SLEEP 2
# define THINK 3
# define PICK_FORK 4

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int long		start_time;
	bool			is_alive;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	bool			is_meal_count_input;
	int				meal_count_input;
	t_philo			*philo;
	pthread_mutex_t	is_alive_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	start_time_lock;
	pthread_mutex_t	*fork_locks;
}	t_data;

typedef struct s_philo
{
	int					philo_id;
	pthread_t			thread_id;
	int					num_of_meals;
	long int			last_meal;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
}	t_philo;

int long	ft_atol(char *str);
bool		input_checker(int argc, char **argv);

t_data		init_data(int argc, char **argv);
bool		allocate_fork_lock(t_data *data);
bool		allocate_philo(t_data *data);

bool		eat(t_philo *philo);
int			start_simulation(t_data *data);

int long	get_current_time(void);
void		simulate_activity_duration(int long waiting_time, t_philo *philo);

void		*supervise(t_data *data);
void		clean(t_data *data);

void		error_msg(int error_num);
void		print_msg(t_philo *philo, int flag);

#endif