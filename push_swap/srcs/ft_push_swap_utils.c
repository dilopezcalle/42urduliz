/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:11:51 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/31 12:34:10 by dilopez-         ###   ########.fr       */
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

void	ft_lst_index(t_list **stack_a)
{
	t_list	*begin;
	int		min;
	int		size;
	int		index;

	begin = *stack_a;
	size = ft_lstlen(*stack_a);
	min = (*stack_a)->number;
	index = 0;
	while (index < size)
	{
		while (*stack_a != 0)
		{
			if ((*stack_a)->index == -1 && (*stack_a)->number < min)
				min = (*stack_a)->number;
			*stack_a = (*stack_a)->next;
		}
		*stack_a = begin;
		while ((*stack_a)->number != min)
			*stack_a = (*stack_a)->next;
		(*stack_a)->index = index;
		*stack_a = begin;
		min = 2147483647;
		index++;
	}
}

int	ft_lstlen(t_list *stack_a)
{
	int	size;

	size = 0;
	while (stack_a != 0)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}
