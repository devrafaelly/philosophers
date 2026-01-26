/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:14:38 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/01/26 00:06:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>

t_rules	*init_program(int ac, int *n)
{
	t_rules rules;
	
	rules->number_of_philosophers = n[0];
	rules->time_to_die = n[1];
	rules->time_to_eat = n[2];
	rules->time_to_sleep = n[3];
	rules->number_of_times_each_philosopher_must_eat = 0;
	if (ac == 6)
		rules->number_of_times_each_philosopher_must_eat = n[4];
	return (rules);
}
