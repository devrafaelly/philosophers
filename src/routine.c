/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:59:46 by codespace         #+#    #+#             */
/*   Updated: 2026/02/02 20:57:11 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_drop_forks(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	print_log(t_philo *philo, char *s);

void	philo_routine(t_philo *philo)
{
	long long	time;

	time = timestamp(philo);
	if (!time)
		return ;
	while (1)
	{
		print_log(philo, "is thinking");
		philo_take_forks(philo);
		philo_eat(philo);
		philo_drop_forks(philo);
		philo_sleep(philo);
	}
}
