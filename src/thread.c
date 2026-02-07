/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:19:00 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 17:08:17 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long long	get_current_time(void);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);

void	create_threads(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = data->philo;
	data->start_time = get_current_time();
	i = 0;
	while (i < data->n_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, philo_routine, &philo[i]);
		i++;
	}
	pthread_create(&data->monitor, NULL, monitor_routine, data);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
}
