/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:44:50 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/02 21:01:50 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_rules	*rules;
	int		*numbers;
	int		i;

	if (ac < 5 || ac > 6)
		return (printf("Error: wrong number of arguments\n"), 1);
	numbers = parse_args(ac, av);
	if (!numbers)
		return (printf("Error: invalid arguments\n"), 1);
	rules = init_program(ac, numbers);
	if (!rules)
		return (1);
	philo_init(rules);
	// iniciar a rotina
	i = 0;
	while (i < rules->number_of_philosophers)
		pthread_mutex_destroy(&rules->forks[i++]);
	pthread_mutex_destroy(&rules->log);
	free(numbers);
	free(rules->forks);
	free(rules);
	return (0);
}
