/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:37:43 by devrafaelly       #+#    #+#             */
/*   Updated: 2026/02/07 14:09:36 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <sys/time.h>

long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	timestamp(t_data *data)
{
	return (get_current_time() - data->start_time);
}
