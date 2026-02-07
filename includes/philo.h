/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:55:03 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 14:51:51 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	pthread_t		monitor;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_t_must_eat;
	int				stop_flag;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
	pthread_mutex_t	init_time;
	pthread_mutex_t	death;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				philo_id;
	long			last_meal;
	pthread_mutex_t	meal;
	t_data			*data;
}	t_philo;

int			*parse_args(int ac, char **av);
void 		data_init(t_data *data, int ac, int *input);
void 		create_threads(t_data *data);
void 		join_threads(t_data *data);
void		data_cleanup(t_data *data);

#endif