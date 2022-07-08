/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:03:00 by dilopez-          #+#    #+#             */
/*   Updated: 2022/07/08 19:05:12 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdlib.h>

static t_philo	*ft_new_philo(int id, t_philo *before);

void	ft_get_philos(t_data *data)
{
	int		i;
	t_philo	*new;
	t_philo	*aux;
	
	data->lst_philo = 0;
	aux = 0;
	i = 1;
	while (i <= data->num_philos)
	{
		printf("index: %d\n", i);
		new = ft_new_philo(i, aux);
		if (!aux)
		{
			aux = new;
			data->lst_philo = aux;
		}
		else
		{
			aux->right = new;
			//aux = aux->right;

			//printf("aux: %d\n", aux->id);
		}
		i++;
	}
	while (data->lst_philo)
	{
		printf("philo id: %d\n", data->lst_philo->id);
		data->lst_philo = (data->lst_philo)->right;
	}
	//printf("aux id: %d\n", data->lst_philo->id);
}

static t_philo	*ft_new_philo(int id, t_philo *before)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo *));
	new->id = id;
	new->fork = 1;
	new->left = before;
	return (new);
}