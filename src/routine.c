/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:59:46 by codespace         #+#    #+#             */
/*   Updated: 2026/02/10 15:04:10 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>

long long	timestamp(t_data *data);
int			get_stop(t_data *data);
void		ft_usleep(t_data *data, int ms);
void		print_log(t_philo *philo, char *s);
static int	philo_take_forks(t_philo *philo);
static void	philo_eat(t_philo *philo);
static void	philo_sleep(t_philo *philo);
static void	philo_think(t_philo *philo);

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
		usleep(50);
	while (!get_stop(philo->data))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static int	philo_take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&(philo->data->forks[philo->right]));
		pthread_mutex_lock(&(philo->data->forks[philo->left]));
	}
	else
	{
		pthread_mutex_lock(&(philo->data->forks[philo->left]));
		pthread_mutex_lock(&(philo->data->forks[philo->right]));
	}
	if (get_stop(philo->data))
	{
		pthread_mutex_unlock(&philo->data->forks[philo->right]);
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		return (0);
	}
	print_log(philo, "has taken a fork");
	print_log(philo, "has taken a fork");
	return (1);
}

static void	philo_eat(t_philo *philo)
{
	long long	time;

	if (!philo_take_forks(philo))
		return ;
	pthread_mutex_lock(&philo->meal);
	time = timestamp(philo->data);
	philo->last_meal = time;
	philo->times_eaten++;
	if (philo->times_eaten == philo->data->n_t_must_eat)
	{
		pthread_mutex_lock(&philo->data->full);
		philo->data->is_full++;
		pthread_mutex_unlock(&philo->data->full);
	}
	pthread_mutex_unlock(&philo->meal);
	print_log(philo, "is eating");
	ft_usleep(philo->data, philo->data->t_eat);
	pthread_mutex_unlock(&(philo->data->forks[philo->right]));
	pthread_mutex_unlock(&(philo->data->forks[philo->left]));
}

static void	philo_sleep(t_philo *philo)
{
	if (get_stop(philo->data))
		return ;
	print_log(philo, "is sleeping");
	ft_usleep(philo->data, philo->data->t_sleep);
}

static void	philo_think(t_philo *philo)
{
	if (get_stop(philo->data))
		return ;
	print_log(philo, "is thinking");
	if (philo->data->n_philo % 2 != 0)
		usleep(1000);
}
