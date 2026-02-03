/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:55:03 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/02 20:52:56 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

typedef struct s_rules
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		start_time;
	pthread_mutex_t	log;
	pthread_mutex_t	*forks;
}	t_rules;

typedef struct s_philo
{
	int				philo_id;
	long long		last_meal;
	pthread_mutex_t	meal;
	t_rules			*rules;
}	t_philo;

int			*parse_args(int ac, char **av);
t_rules		*init_program(int ac, int *n);
void		philo_routine(t_philo *philo);
void		philo_init(t_rules *rules);
long long	timestamp(t_philo *philo);

#endif