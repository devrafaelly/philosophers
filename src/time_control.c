/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:37:43 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 16:47:30 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <unistd.h>
#include <sys/time.h>

int	get_stop(t_data *data);

long long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long long	timestamp(t_data *data)
{
	return (get_current_time() - data->start_time);
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
