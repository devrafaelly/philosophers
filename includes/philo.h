/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:55:03 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/09 16:56:47 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

# define C_RESET   "\033[0m"
# define C_EAT     "\033[92m"
# define C_SLEEP   "\033[96m"
# define C_THINK   "\033[94m"
# define C_FORK    "\033[93m"
# define C_DIE     "\033[31m"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		monitor;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_t_must_eat;
	int				is_full;
	int				stop_flag;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	log;
	pthread_mutex_t	full;
	pthread_mutex_t	death;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_t		thread_id;
	int				philo_id;
	int				left;
	int				right;
	int				times_eaten;
	long long		last_meal;
	pthread_mutex_t	meal;
}	t_philo;

int			*parse_args(int ac, char **av);
void		data_init(t_data *data, int ac, int *input);
void		create_threads(t_data *data);
void		join_threads(t_data *data);
void		data_cleanup(t_data *data);

#endif