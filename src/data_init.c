/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:14:38 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/03 20:40:55 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long long	get_current_time(void);
static void	set_data(t_data *data, int ac, int *n);
static int	set_arrays(t_data *data);

t_data	*data_init(int ac, int *n)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}
	set_data(data, ac, n);
	if (!set_arrays(data))
	{
		free(data);
		return (NULL);
	}
	i = 0;
	while (i < n[0])
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->log, NULL);
	pthread_mutex_init(&data->init_time, NULL);
	pthread_mutex_init(&data->death, NULL);
	return (data);
}

static void	set_data(t_data *data, int ac, int *n)
{
	data->n_philo = n[0];
	data->t_die = n[1];
	data->t_eat = n[2];
	data->t_sleep = n[3];
	data->n_t_must_eat = 0;
	if (ac == 6)
		data->n_t_must_eat = n[4];
	data->stop_flag = 0;
}

static int	set_arrays(t_data *data)
{
	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		printf("Error: malloc failed\n");
		return (0);
	}
	data->philo = malloc(data->n_philo * sizeof(t_philo));
	if (!data->philo)
	{
		printf("Error: malloc failed\n");
		free(data->forks);
		return (0);
	}
	return (1);
}
