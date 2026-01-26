/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:44:50 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/01/26 00:22:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_rules	rules;
	int	*numbers;
	
	if (ac < 5 || ac > 6)
		return (printf("Error: wrong number of arguments\n"), 1);
	numbers = parse_args(ac, av);
	if (!numbers)
		return (printf("Error: malloc failed\n"), 1);
	rules = init_program(ac, numbers);
	if (!rules)
		return (free(numbers), printf("Error: malloc failed\n"), 1);
	free(numbers);
	free(rules);
	return (0);
}
