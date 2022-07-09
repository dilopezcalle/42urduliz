/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:41:20 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/09 15:12:56 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static void	ft_error_args(void);

int main(int argc, char *argv[])
{	
	if (argc < 5)
	{
		ft_error_args();
		return (0);
	}
	ft_philo(argc, argv);
	return (0);
}

void	ft_philo(int argc, char *argv[])
{
	t_data	data;
	int		i = 0;
	t_philo	*lst_aux;

	ft_get_args(&data, argc, argv);
	ft_get_philos(&data);
	pthread_mutex_init(&data.mutex, 0);
	pthread_mutex_init(&data.mutex2, 0);
	lst_aux = data.lst_philo;
	pthread_mutex_lock(&data.mutex);
	while (i < data.num_philos)
	{
		pthread_mutex_lock(&data.mutex2);
		pthread_create(&data.lst_philo->thread, 0, ft_philo_states, &data);
		pthread_mutex_unlock(&data.mutex2);
		ft_msleep(1);
		pthread_mutex_lock(&data.mutex2);
		data.lst_philo = data.lst_philo->right;
		pthread_mutex_unlock(&data.mutex2);
		i++;
	}
	pthread_mutex_unlock(&data.mutex);
	/*
	while(1)
		;
	*/
}

static void	ft_error_args(void)
{
	printf("\n\x1b[31m ========== Error: Invalid arguments ==========\x1b[37m\n\n");
	printf("1. number_of_philosophers\n");
	printf("2. time_to_die\n");
	printf("3. time_to_eat\n");
	printf("4. time_to_sleep\n");
	printf("5. [number_of_times_each_philosopher_must_eat]\n\n");
}