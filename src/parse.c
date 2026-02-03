/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:24:51 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/02 21:09:47 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long		ft_atol(const char *nptr);
int			ft_isdigit(int c);
static int	validate_input(char *s);
static void	*input_error_handler(int *numbers);

int	*parse_args(int ac, char **av)
{
	int		*numbers;
	long	n;
	int		i;

	numbers = malloc((ac - 1) * sizeof(int));
	if (!numbers)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (av[i + 1])
	{
		if (!validate_input(av[i + 1]))
			return (input_error_handler(numbers));
		n = ft_atol(av[i + 1]);
		if (n > 2147483647)
			return (input_error_handler(numbers));
		if (n <= 0)
			return (input_error_handler(numbers));
		numbers[i] = n;
		i++;
	}
	return (numbers);
}

static int	validate_input(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static void	*input_error_handler(int *numbers)
{
	printf("Error: invalid input\n");
	free(numbers);
	return (NULL);
}
