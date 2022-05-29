/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:11:51 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/29 13:51:27 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_issorted(t_list **stack_a)
{
	t_list	*aux;

	aux = *stack_a;
	while (aux->next != 0)
	{
		if (aux->number > (aux->next)->number)
			return (0);
		aux = aux->next;
	}
	return (1);
}
