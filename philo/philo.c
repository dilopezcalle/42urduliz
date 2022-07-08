/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:41:20 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/08 19:03:07 by dilopez-         ###   ########.fr       */
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

	ft_get_args(&data, argc, argv);
	ft_get_philos(&data);
	
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