/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:47:47 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/10 17:01:05 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_take_fork(t_philo *philo, t_data *data);

void	*ft_philo_states(void *param)
{
	t_data	*data;
	t_philo	*aux;
	
	data = (t_data *)param;
	aux = data->lst_philo;
	// pthread_mutex_lock(&data->mutex);
	// pthread_mutex_unlock(&data->mutex);
	while (1) // Cambiar a mientras que el philo siga vivo
	{
		if (ft_take_fork(aux, data))
		{
			aux->last_eat = 0;
			printf("%ld %d is eating\n", ft_timecomp(data->init_time), aux->id);
			ft_msleep(data->time_eat, aux, data);
			*aux->taken_fork_1 = 1;
			*aux->taken_fork_2 = 1;
			aux->num_forks = 0;
			printf("%ld %d is sleeping\n", ft_timecomp(data->init_time), aux->id);
			ft_msleep(data->time_sleep, aux, data);
			aux->last_eat -= data->time_sleep;
			printf("%ld %d is thinking\n", ft_timecomp(data->init_time), aux->id);
		}
	}
	return (0);
}

static int	ft_take_fork(t_philo *philo, t_data *data)
{
	while (philo->num_forks < 2)
	{
		//pthread_mutex_lock(&data->mutex);
		if (ft_timecomp(data->init_time) - philo->last_eat > data->time_die)
		{
			printf("\n%ld PHILO %d DIED\n\n", ft_timecomp(data->init_time), philo->id);
			exit (0);
		}
		if (philo->num_forks < 2 && philo->fork)
		{
			printf("%ld %d has taken a fork\n", ft_timecomp(data->init_time), philo->id);
			philo->fork = 0;
			if (!philo->taken_fork_1)
				philo->taken_fork_1 = &philo->fork;
			else
				philo->taken_fork_2 = &philo->fork;
			(philo->num_forks)++;
		}
		if (philo->num_forks < 2 && (philo->right)->fork)
		{
			printf("%ld %d has taken a fork\n", ft_timecomp(data->init_time), philo->id);
			(philo->right)->fork = 0;
			if (!philo->taken_fork_1)
				philo->taken_fork_1 = &(philo->right)->fork;
			else
				philo->taken_fork_2 = &(philo->right)->fork;
			(philo->num_forks)++;
		}
		if (philo->num_forks < 2 && (philo->left)->fork)
		{
			printf("%ld %d has taken a fork\n", ft_timecomp(data->init_time), philo->id);
			(philo->left)->fork = 0;
			if (!philo->taken_fork_1)
				philo->taken_fork_1 = &(philo->left)->fork;
			else
				philo->taken_fork_2 = &(philo->left)->fork;
			(philo->num_forks)++;
		}
		/*
		if (philo->num_forks < 2)
		{
			if (philo->taken_fork_1)
				*philo->taken_fork_1 = 1;
			if (philo->taken_fork_2)
				*philo->taken_fork_2 = 1;
			philo->taken_fork_2 = 0;
			philo->taken_fork_1 = 0;
			philo->num_forks = 0;
		}
		*/
		//pthread_mutex_unlock(&data->mutex);
		//usleep(42);
	}
	return (1);
}
