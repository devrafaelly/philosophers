/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:24:51 by devrafaelly       #+#    #+#             */
/*   Updated: 2025/12/21 21:01:55 by devrafaelly      ###   ########.fr       */
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

static int	ft_atoi(const char *nptr)
{
	int	signal;
	int	res;

	signal = 1;
	res = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * signal);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
