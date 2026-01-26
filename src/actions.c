/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 00:42:05 by codespace         #+#    #+#             */
/*   Updated: 2026/01/26 01:10:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <sys/time.h>

long long   timestamp(void)
{
    struct timeval tv;

    if(gettimeofday(&tv, NULL) != 0)
        return (0);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    philo_take_forks(t_rules *rules, t_philo *philo)
{
    int left;
    int right;

    left = philo->philo_id;
    right = (philo->philo_id + 1) % rules->number_of_philosophers;
    if (philo->philo_id % 2 == 0)
    {
        pthread_mutex_lock(&rules->forks[right]);
        pthread_mutex_lock(&rules->forks[left]);
    }
    else
    {
        pthread_mutex_lock(&rules->forks[left]);
        pthread_mutex_lock(&rules->forks[right]);
    }
}

void    philo_eat(t_rules *rules, t_philo *philo)
{
    long long   time;
    
    time = timestamp();
    if (!time)
        return ;
    pthread_mutex_lock(&rules->print_mutex);
    printf("%lld %d is eating.\n", time, philo->philo_id);
    pthread_mutex_unlock(&rules->print_mutex);
    usleep(rules->time_to_eat * 1000);
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal = time;
    pthread_mutex_unlock(&philo->meal_mutex);
}

void    philo_drop_forks(t_rules *rules, t_philo *philo)
{
    int left;
    int right;

    left = philo->philo_id;
    right = (philo->philo_id + 1) % rules->number_of_philosophers;
    if (philo->philo_id % 2 == 0)
    {
        pthread_mutex_unlock(&rules->forks[left]);
        pthread_mutex_unlock(&rules->forks[right]);
    }
    else
    {
        pthread_mutex_unlock(&rules->forks[right]);
        pthread_mutex_unlock(&rules->forks[left]);
    }
}

void    philo_sleep(t_rules *rules, t_philo *philo)
{
    long long   time;
    
    time = timestamp();
    if (!time)
        return ;
    pthread_mutex_lock(&rules->print_mutex);
    printf("%lld %d is sleeping.\n", time, philo->philo_id);
    pthread_mutex_unlock(&rules->print_mutex);
    usleep(rules->time_to_sleep * 1000);
}
