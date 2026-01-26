/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:24:51 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/01/26 04:16:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>

static int	ft_atoi(const char *nptr);
static int	ft_isdigit(int c);
static int	validate_input(char *s);

int	*parse_args(int ac, char **av)
{
	int	*numbers;
	int	n;
	int	i;

	numbers = malloc((ac - 1) * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	while (av[i + 1])
	{
		if (validate_input(av[i + 1]))
		{
			n = ft_atoi(av[i + 1]);
			if (n >= 0)
				numbers[i] = n;
			else
				return (free(numbers), NULL);
		}
		else
			return (free(numbers), NULL);
		i++;
	}
	return (numbers);
}

static int	validate_input(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
