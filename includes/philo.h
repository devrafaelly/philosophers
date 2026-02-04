/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:55:03 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/04 15:35:22 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_t_must_eat;
	int				stop_flag;
	long long		start_time;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
	pthread_mutex_t	init_time;
	pthread_mutex_t	death;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int				philo_id;
	long long		last_meal;
	pthread_t		thread_id;
	pthread_mutex_t	meal;
	t_data			*data;
}	t_philo;

int			*parse_args(int ac, char **av);
t_data		*data_init(int ac, int *n);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);
void		thread_init(t_data *data);
long long	timestamp(t_data *data);
void		data_cleanup(t_data *data);

#endif