/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:44:50 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 14:52:01 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <stdlib.h>

void	data_cleanup(t_data *data);

int	main(int ac, char **av)
{
	t_data	data;
	int		*input;

	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	input = parse_args(ac, av);
	if (!input)
		return (1);
	data_init(&data, ac, input);
	if (!data.philo)
		return (1);
	create_threads(&data);
	join_threads(&data);
	data_cleanup(&data);
	free(input);
	return (0);
}
