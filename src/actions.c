/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:42:05 by codespace         #+#    #+#             */
/*   Updated: 2026/02/03 21:50:12 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdio.h>

int		get_stop(t_data *data);
void	print_log(t_philo *philo, char *s);

void	philo_take_forks(t_philo *philo)
{
	int	left;
	int	right;

	right = philo->philo_id - 1;
	left = philo->philo_id % philo->data->n_philo;
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->data->forks[right]));
		print_log(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->data->forks[left]));
		print_log(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&(philo->data->forks[left]));
		print_log(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->data->forks[right]));
		print_log(philo, "has taken a fork");
	}
}

void	philo_eat(t_philo *philo)
{
	long long	time;

	time = timestamp(philo->data);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = time;
	pthread_mutex_unlock(&philo->meal);
	print_log(philo, "is eating");
	usleep(philo->data->t_eat * 1000);
}

void	philo_drop_forks(t_philo *philo)
{
	int	left;
	int	right;

	right = philo->philo_id - 1;
	left = philo->philo_id % philo->data->n_philo;
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(&(philo->data->forks[left]));
		pthread_mutex_unlock(&(philo->data->forks[right]));
	}
	else
	{
		pthread_mutex_unlock(&(philo->data->forks[right]));
		pthread_mutex_unlock(&(philo->data->forks[left]));
	}
}

void	philo_sleep(t_philo *philo)
{
	print_log(philo, "is sleeping");
	usleep(philo->data->t_sleep * 1000);
}
