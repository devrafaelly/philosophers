/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:56:00 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 16:51:08 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>

long long	timestamp(t_data *data);
void		print_log(t_philo *philo, char *s);
static int	death_check(t_data *data);
static int	satisfaction_check(t_data *data);
int			get_stop(t_data *data);
static void	set_stop(t_data *data);

void	*monitor_routine(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	while (!get_stop(data))
	{
		if (death_check(data))
			return (NULL);
		if (satisfaction_check(data))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

static int	death_check(t_data *data)
{
	t_philo		*philo;
	long long	time;
	long long	last;
	int			i;

	philo = data->philo;
	i = 0;
	while (i < data->n_philo)
	{
		time = timestamp(data);
		pthread_mutex_lock(&philo[i].meal);
		last = philo[i].last_meal;
		pthread_mutex_unlock(&philo[i].meal);
		if (time - last > data->t_die)
		{
			print_log(&philo[i], "died");
			set_stop(data);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	satisfaction_check(t_data *data)
{
	t_philo		*philo;
	int			i;

	philo = data->philo;
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_lock(&data->philo[i].meal);
		if (!philo[i].satisfaction)
		{
			pthread_mutex_unlock(&data->philo->meal);
			return (0);
		}
		pthread_mutex_unlock(&data->philo[i].meal);
		i++;
	}
	set_stop(data);
	return (1);
}

int	get_stop(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->death);
	stop = data->stop_flag;
	pthread_mutex_unlock(&data->death);
	return (stop);
}

static void	set_stop(t_data *data)
{
	pthread_mutex_lock(&data->death);
	data->stop_flag = 1;
	pthread_mutex_unlock(&data->death);
}
