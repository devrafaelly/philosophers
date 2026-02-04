/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:19:00 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/03 21:08:46 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long long	get_current_time(void);
static int	create_threads(t_data *data, pthread_t *thread_id,
				pthread_t *monitor);
static int	join_threads(t_data *data, pthread_t *thread_id, pthread_t monitor);

void	thread_init(t_data *data)
{
	pthread_t	*thread_id;
	pthread_t	monitor;

	thread_id = malloc(data->n_philo * sizeof(pthread_t));
	if (!thread_id)
	{
		printf("Error: malloc failed\n");
		return ;
	}
	if (create_threads(data, thread_id, &monitor) != 0)
	{
		free(thread_id);
		return ;
	}
	if (join_threads(data, thread_id, monitor) != 0)
	{
		free(thread_id);
		return ;
	}
	free(thread_id);
}

static int	create_threads(t_data *data, pthread_t *thread_id,
				pthread_t *monitor)
{
	int	i;

	pthread_mutex_lock(&data->init_time);
	data->start_time = get_current_time();
	pthread_mutex_unlock(&data->init_time);
	i = 0;
	while (i < data->n_philo)
	{
		data->philo[i].philo_id = i + 1;
		data->philo[i].last_meal = 0;
		data->philo[i].data = data;
		pthread_mutex_init(&data->philo[i].meal, NULL);
		if (pthread_create(&thread_id[i], NULL, philo_routine,
				&data->philo[i]) != 0)
		{
			printf("Error: thread creation failed\n");
			while (--i >= 0)
				pthread_join(thread_id[i], NULL);
			return (1);
		}
		i++;
	}
	if (pthread_create(monitor, NULL, monitor_routine, data) != 0)
		return (printf("Error: thread creation failed\n"), 1);
	return (0);
}

static int	join_threads(t_data *data, pthread_t *thread_id, pthread_t monitor)
{
	int	i;

	if (pthread_join(monitor, NULL) != 0)
	{
		printf("Error: thread join failed\n");
		return (1);
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(thread_id[i], NULL) != 0)
		{
			printf("Error: thread join failed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

// static void	*monitor_thread(void *arg)
// {
// 	monitor_routine((t_data *)arg);
// 	return (NULL);
// }

// static void	*philo_thread(void *arg)
// {
// 	philo_routine((t_philo *)arg);
// 	return (NULL);
// }
