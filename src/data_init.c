/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:14:38 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/09 17:06:02 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long long	get_current_time(void);
static int	set_philo(t_data *data);
static int	set_forks(t_data *data);

void	data_init(t_data *data, int ac, int *input)
{
	data->n_philo = input[0];
	data->t_die = input[1];
	data->t_eat = input[2];
	data->t_sleep = input[3];
	data->n_t_must_eat = -1;
	if (ac == 6)
		data->n_t_must_eat = input[4];
	data->is_full = 0;
	data->stop_flag = 0;
	if (!set_philo(data))
		return ;
	if (!set_forks(data))
	{
		free(data->philo);
		return ;
	}
	pthread_mutex_init(&data->log, NULL);
	pthread_mutex_init(&data->full, NULL);
	pthread_mutex_init(&data->death, NULL);
}

static int	set_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = malloc(data->n_philo * sizeof(t_philo));
	if (!philo)
	{
		printf("Error: malloc failed\n");
		return (0);
	}
	i = 0;
	while (i < data->n_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].left = i;
		philo[i].right = (i + 1) % data->n_philo;
		philo[i].times_eaten = 0;
		philo[i].last_meal = 0;
		philo[i].data = data;
		pthread_mutex_init(&philo[i].meal, NULL);
		i++;
	}
	data->philo = philo;
	return (1);
}

static int	set_forks(t_data *data)
{
	int	i;

	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		printf("Error: malloc failed\n");
		return (0);
	}
	i = 0;
	while (i < data->n_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (1);
}
