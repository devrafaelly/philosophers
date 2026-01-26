/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:55:03 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/01/26 01:02:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

typedef struct	s_fork
{
	int	*fork;
}	t_fork;

typedef struct s_philo
{
	int			philo_id;
	long long	last_meal;
}	t_philo;

typedef struct s_rules
{
	number_of_philosophers;
	time_to_die;
	time_to_eat;
	time_to_sleep;
	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	print_mutex;
    pthread_mutex_t	*forks;
}	t_rules;

#endif