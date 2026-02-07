/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 04:15:48 by codespace         #+#    #+#             */
/*   Updated: 2026/02/07 15:50:09 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <stdio.h>

long long	timestamp(t_data *data);
int			get_stop(t_data *data);

void	print_log(t_philo *philo, char *s)
{
	long long	time;

	pthread_mutex_lock(&(philo->data->log));
	time = timestamp(philo->data);
	if (!get_stop(philo->data))
		printf("%lld %d %s\n", time, philo->philo_id, s);
	pthread_mutex_unlock(&(philo->data->log));
}

void	ft_usleep(t_data *data, int ms)
{
	long long	time;

	time = timestamp(data);
	while ((timestamp(data) - time) < ms)
	{
		if (get_stop(data))
			return ;
		usleep(50);
	}
}

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
