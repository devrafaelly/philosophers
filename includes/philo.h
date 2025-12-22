/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:55:03 by devrafaelly       #+#    #+#             */
/*   Updated: 2025/12/21 21:07:50 by devrafaelly      ###   ########.fr       */
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

struct timeval tv;

typedef struct s_philo
{
	int		philo_id;
	long long	last_meal; // (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}	t_philo;

typedef struct s_rules
{
	number_of_philosophers;
	time_to_die;
	time_to_eat;
	time_to_sleep;
	number_of_times_each_philosopher_must_eat;
}	t_rules;

#endif