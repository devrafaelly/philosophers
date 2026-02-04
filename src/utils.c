/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 04:15:48 by codespace         #+#    #+#             */
/*   Updated: 2026/02/03 21:33:26 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>

int	get_stop(t_data *data);

long	ft_atol(const char *nptr)
{
	int		signal;
	long	res;

	signal = 1;
	res = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signal = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * signal);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	print_log(t_philo *philo, char *s)
{
	long long	time;

	if (get_stop(philo->data))
		return ;
	time = timestamp(philo->data);
	pthread_mutex_lock(&(philo->data->log));
	printf("%lld %d %s\n", time, philo->philo_id, s);
	pthread_mutex_unlock(&(philo->data->log));
}
