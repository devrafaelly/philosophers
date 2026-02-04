/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:19:00 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/04 15:38:47 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long long	get_current_time(void);
static int	create_threads(t_data *data);
static int	join_threads(t_data *data);

void	thread_init(t_data *data)
{
	if (create_threads(data) != 0)
		return ;
	if (join_threads(data) != 0)
		return ;
}

static int	create_threads(t_data *data)
{
	int	i;

	if (pthread_create(&data->monitor, NULL, monitor_routine, data) != 0)
		return (printf("Error: thread creation failed\n"), 1);
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
		if (pthread_create(&data->philo[i].thread_id, NULL, philo_routine,
				&data->philo[i]) != 0)
		{
			printf("Error: thread creation failed\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->philo[i].thread_id, NULL) != 0)
		{
			printf("Error: thread join failed\n");
			return (1);
		}
		i++;
	}
	if (pthread_join(data->monitor, NULL) != 0)
	{
		printf("Error: thread join failed\n");
		return (1);
	}
	return (0);
}
