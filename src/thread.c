/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:19:00 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 14:40:31 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long		get_current_time(void);
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
		if (pthread_create(&philo[i].thread_id, NULL, philo_routine,
				&philo[i]) != 0)
		{
			printf("Error: thread creation failed\n");
			return ;
		}
		i++;
	}
	if (pthread_create(&data->monitor, NULL, monitor_routine, data) != 0)
	{
		printf("Error: thread creation failed\n");
		return ;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->philo[i].thread_id, NULL) != 0)
		{
			printf("Error: thread join failed\n");
			return ;
		}
		i++;
	}
	if (pthread_join(data->monitor, NULL) != 0)
	{
		printf("Error: thread join failed\n");
		return ;
	}
}
