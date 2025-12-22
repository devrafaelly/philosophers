/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devrafaelly <devrafaelly@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:02:45 by devrafaelly       #+#    #+#             */
/*   Updated: 2025/12/21 20:43:45 by devrafaelly      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <sys/time.h> //gettimeofday := int gettimeofday(struct timeval *restrict tv, struct timezone *_Nullable restrict tz);

// if (!gettimeofday(&tv, NULL))
// 	return (1);