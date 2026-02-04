/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:59:46 by codespace         #+#    #+#             */
/*   Updated: 2026/02/04 16:04:10 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>

void		philo_take_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_drop_forks(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		ft_usleep(t_data *data, int ms);
void		print_log(t_philo *philo, char *s);
int			get_stop(t_data *data);
static void	set_stop(t_data *data);
static int	death_check(t_data *data);

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_philo == 1)
	{
		print_log(philo, "has taken a fork");
		ft_usleep(philo->data, philo->data->t_die);
		return (NULL);
	}
	if (philo->philo_id % 2 != 0)
		usleep(1000);
	while (!get_stop(philo->data))
	{
		philo_take_forks(philo);
		philo_eat(philo);
		philo_drop_forks(philo);
		philo_sleep(philo);
		print_log(philo, "is thinking");
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	while (!get_stop(data))
	{
		if (!death_check(data))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}

static int	death_check(t_data *data)
{
	long long	time;
	long long	last;
	int			i;
	
	i = 0;
	while (i < data->n_philo)
	{
		time = timestamp(data);
		pthread_mutex_lock(&data->philo[i].meal);
		last = data->philo[i].last_meal;
		pthread_mutex_unlock(&data->philo[i].meal);
		if (time - last > data->t_die)
		{
			print_log(&data->philo[i], "died");
			set_stop(data);
			return (0);
		}
		i++;
	}
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
