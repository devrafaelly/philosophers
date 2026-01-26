/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 23:59:46 by codespace         #+#    #+#             */
/*   Updated: 2026/01/26 01:10:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

long long   timestamp(void);
void        philo_take_forks(t_rules *rules, t_philo *philo);
void        philo_eat(t_rules *rules, t_philo *philo);
void        philo_drop_forks(t_rules *rules, t_philo *philo);
void        philo_sleep(t_rules *rules, t_philo *philo);

void    philo_routine(t_rules *rules, t_philo *philo)
{
    long long   time;
    
    time = timestamp();
    if (!time)
        return ;
    while ()
    {
        pthread_mutex_lock(&rules->print_mutex);
        printf("%lld %d is thinking.\n", time, philo->philo_id);
        pthread_mutex_unlock(&rules->print_mutex);
        philo_take_forks(rules, philo);
        philo_eat(rules, philo);
        philo_drop_forks(rules, philo);
        philo_sleep(rules, philo);
    }
}
