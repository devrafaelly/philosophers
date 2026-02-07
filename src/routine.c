/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:59:46 by codespace         #+#    #+#             */
/*   Updated: 2026/02/07 16:48:54 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>

void		philo_take_forks(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		ft_usleep(t_data *data, int ms);
void		print_log(t_philo *philo, char *s);
int			get_stop(t_data *data);

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
		usleep(100);
	while (!get_stop(philo->data))
	{
		philo_take_forks(philo);
		philo_eat(philo);
		pthread_mutex_unlock(&(philo->data->forks[philo->right]));
		pthread_mutex_unlock(&(philo->data->forks[philo->left]));
		philo_sleep(philo);
		print_log(philo, "is thinking");
	}
	return (NULL);
}
