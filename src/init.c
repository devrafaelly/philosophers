/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:14:38 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/02 20:54:29 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long long	get_current_time(void);
static int	create_threads(t_philo *philo, pthread_t *thread_id,
				t_rules *rules);
static int	join_threads(t_philo *philo, pthread_t *thread_id);
static void	cleanup_thread(t_philo *philo);

t_rules	*init_program(int ac, int *n)
{
	t_rules	*rules;
	int		i;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (printf("Error: malloc failed\n"), NULL);
	rules->number_of_philosophers = n[0];
	rules->time_to_die = n[1];
	rules->time_to_eat = n[2];
	rules->time_to_sleep = n[3];
	rules->number_of_times_each_philosopher_must_eat = 0;
	if (ac == 6)
		rules->number_of_times_each_philosopher_must_eat = n[4];
	rules->start_time = get_current_time();
	rules->forks = malloc(n[0] * sizeof(pthread_mutex_t));
	if (!rules->forks)
	{
		printf("Error: malloc failed\n");
		return (free(rules), NULL);
	}
	i = 0;
	while (i < n[0])
		pthread_mutex_init(&rules->forks[i++], NULL);
	pthread_mutex_init(&rules->log, NULL);
	return (rules);
}

void	philo_init(t_rules *rules)
{
	pthread_t	*thread_id;
	t_philo		*philo;
	int			ret;

	thread_id = malloc(rules->number_of_philosophers * sizeof(pthread_t));
	if (!thread_id)
		return ;
	philo = malloc(rules->number_of_philosophers * sizeof(t_philo));
	if (!philo)
		return (free(thread_id));
	ret = create_threads(philo, thread_id, rules);
	if (ret != 0)
		return ;
	ret = join_threads(philo, thread_id);
	if (ret != 0)
		return ;
	cleanup_thread(philo);
	free(thread_id);
	free(philo);
}

static int	create_threads(t_philo *philo, pthread_t *thread_id, t_rules *rules)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < rules->number_of_philosophers)
	{
		philo[i].philo_id = i + 1;
		philo[i].last_meal = 0;
		philo[i].rules = rules;
		pthread_mutex_init(&philo[i].meal, NULL);
		ret = pthread_create(&thread_id[i], NULL,
				(void *)philo_routine, &philo[i]);
		if (ret != 0)
		{
			printf("Error: thread creation failed\n");
			while (--i >= 0)
				pthread_join(thread_id[i], NULL);
			return (ret);
		}
		i++;
	}
	return (0);
}

static int	join_threads(t_philo *philo, pthread_t *thread_id)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < philo->rules->number_of_philosophers)
	{
		ret = pthread_join(thread_id[i], NULL);
		if (ret != 0)
			printf("Error: thread join failed\n");
		i++;
	}
	return (0);
}

static void	cleanup_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->number_of_philosophers)
	{
		pthread_mutex_destroy(&philo[i].meal);
		i++;
	}
}
