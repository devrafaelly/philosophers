/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 02:44:50 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/04 16:22:21 by rafaoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
#include <stdlib.h>

void	data_cleanup(t_data *data);

int	main(int ac, char **av)
{
	t_data	*data;
	int		*numbers;

	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	numbers = parse_args(ac, av);
	if (!numbers)
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	data = data_init(ac, numbers);
	if (!data)
		return (1);
	thread_init(data);
	data_cleanup(data);
	free(numbers);
	return (0);
}
