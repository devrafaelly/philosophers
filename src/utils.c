/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 04:15:48 by codespace         #+#    #+#             */
/*   Updated: 2026/02/07 16:47:07 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>

long long	timestamp(t_data *data);
int			get_stop(t_data *data);
static char	*get_color(char *s);
static int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	print_log(t_philo *philo, char *s)
{
	char		*color;
	long long	time;

	pthread_mutex_lock(&(philo->data->log));
	time = timestamp(philo->data);
	if (!get_stop(philo->data))
	{
		color = get_color(s);
		printf("%s%lld %d %s%s\n", color, time, philo->philo_id, s, C_RESET);
	}
	pthread_mutex_unlock(&(philo->data->log));
}

static char	*get_color(char *s)
{
	if (!ft_strncmp(s, "is eating", 9))
		return (C_EAT);
	if (!ft_strncmp(s, "is sleeping", 11))
		return (C_SLEEP);
	if (!ft_strncmp(s, "is thinking", 11))
		return (C_THINK);
	if (!ft_strncmp(s, "has taken a fork", 16))
		return (C_FORK);
	if (!ft_strncmp(s, "died", 4))
		return (C_DIE);
	return (C_RESET);
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

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
