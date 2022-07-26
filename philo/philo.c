/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:41:20 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/10 17:00:54 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

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

	memset(&data, 0, sizeof(t_data));
	ft_get_args(&data, argc, argv);
	ft_get_philos(&data);
	gettimeofday(&data.init_time, NULL);
	pthread_mutex_init(&data.mutex, 0);
	pthread_mutex_init(&data.mutex2, 0);
	pthread_mutex_lock(&data.mutex);
	while (i < data.num_philos)
	{
		//printf("%d\n", data.lst_philo->right->id);
		pthread_create(&data.lst_philo->thread, 0, ft_philo_states, &data);
		//pthread_mutex_lock(&data.mutex2);
		data.lst_philo = data.lst_philo->right;
		//usleep(42);
		//pthread_mutex_lock(&data.mutex2);
		i++;
	}
		pthread_mutex_unlock(&data.mutex);
	i = 0;
	pthread_mutex_init(&data.mutex2, 0);
	while (i < data.num_philos)
	{
		pthread_join(data.lst_philo->thread, 0);
		data.lst_philo = data.lst_philo->right;
		//usleep(42);
		i++;
	}
	exit (0);
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