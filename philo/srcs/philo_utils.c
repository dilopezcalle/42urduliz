/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:00:35 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/10 17:00:11 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_msleep(long milisecons, t_philo *philo, t_data *data)
{
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	while (milisecons > ft_timecomp(timer))
	{
		if ((ft_timecomp(data->init_time) - philo->last_eat) > data->time_die)
		{
			printf("%ld %d died\n", ft_timecomp(data->init_time), philo->id);
			exit(0);
		}
		usleep(500);
	}
	philo->last_eat = ft_timecomp(data->init_time);
}

long	ft_timecomp(struct timeval timer)
{
	struct timeval	tp;
	long			result;

	gettimeofday(&tp, NULL);
	result = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	result -= (timer.tv_sec * 1000) + (timer.tv_usec / 1000);
	return (result);
}
