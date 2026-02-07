/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:24:51 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/05 19:48:39 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>

long		ft_atol(const char *nptr);
int			ft_isdigit(int c);
static int	validate_input(char *s);
static void	*input_error_handler(int *input);

int	*parse_args(int ac, char **av)
{
	int		*input;
	long	n;
	int		i;

	input = malloc((ac - 1) * sizeof(int));
	if (!input)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}
	i = 0;
	while (av[i + 1])
	{
		if (!validate_input(av[i + 1]))
			return (input_error_handler(input));
		n = ft_atol(av[i + 1]);
		if (n > 2147483647)
			return (input_error_handler(input));
		if (n <= 0)
			return (input_error_handler(input));
		input[i] = n;
		i++;
	}
	return (input);
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

static void	*input_error_handler(int *input)
{
	printf("Error: invalid input\n");
	free(input);
	return (NULL);
}
