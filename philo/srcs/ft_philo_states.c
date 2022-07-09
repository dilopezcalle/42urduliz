/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:47:47 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/09 15:11:00 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_take_fork(t_philo *philo);

void	*ft_philo_states(void *param)
{
	t_data	*data;
	t_philo	*aux;
	
	data = (t_data *)param;
	pthread_mutex_lock(&data->mutex2);
	aux = data->lst_philo;
	pthread_mutex_unlock(&data->mutex2);
	while (1)
	{
		if (ft_take_fork(aux))
		{
			printf("Philo (%p) con id %d can eat\n", aux, (aux)->id);
			ft_msleep(data->time_eat);
			printf("forks: %d\n", aux->forks);
			while (aux->forks > 0)
			{
				if (aux->fork == 0 && aux->forks > 0)
				{
					printf("philo %d deja el fork\n", aux->id);
					aux->fork = 1;
					(aux->forks)--;
				}
				if ((aux->right)->fork == 0 && aux->forks > 0)
				{
					printf("philo %d deja el fork derecha\n", aux->id);
					(aux->right)->fork = 1;
					(aux->forks)--;
				}
				if ((aux->left)->fork == 0 && aux->forks > 0)
				{
					printf("philo %d deja el fork izquierda\n", aux->id);
					(aux->right)->fork = 1;
					(aux->forks)--;
				}
			}
		}
	}
	return (0);
}

static int	ft_take_fork(t_philo *philo)
{
	philo->forks = 0;
	while (philo->forks < 2)
	{
		if (philo->fork && philo->forks < 2)
		{
			printf("Philo %d taken his fork\n", philo->id);
			philo->fork = 0;
			(philo->forks)++;
		}
		if ((philo->right)->fork && philo->forks < 2)
		{
			printf("Philo %d taken the right fork\n", philo->id);
			(philo->right)->fork = 0;
			(philo->forks)++;
		}
		if ((philo->right)->fork && philo->forks < 2)
		{
			printf("Philo %d taken the left fork\n", philo->id);
			(philo->left)->fork = 0;
			(philo->forks)++;
		}
	}
	return (1);
}
