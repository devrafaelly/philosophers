/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:45:30 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 14:42:03 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>

void	data_cleanup(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->philo)
	{
		i = 0;
		while (i < data->n_philo)
			pthread_mutex_destroy(&data->philo[i++].meal);
		free(data->philo);
	}
	if (data->forks)
	{
		i = 0;
		while (i < data->n_philo)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
	}
	pthread_mutex_destroy(&data->init_time);
	pthread_mutex_destroy(&data->log);
	pthread_mutex_destroy(&data->death);
}
