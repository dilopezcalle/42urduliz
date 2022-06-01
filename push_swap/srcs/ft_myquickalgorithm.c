/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:32:34 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/01 08:57:56 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_algorithm(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	int		j;
	int		half;
	t_list	*begin;

	i = 0;
	j = 0;
	while (size > 0)
	{
		begin = *stack_a;
		half = size / 2;
		size--;
		while ((*stack_a)->index != j)
		{
			*stack_a = (*stack_a)->next;
			i++;
		}
		*stack_a = begin;
		if (i <= half)
			while (i > 0)
			{
				ra(stack_a);
				i--;
			}
		else
			while (i <= size)
			{
				rra(stack_a);
				i++;
			}
		j++;
		i = 0;
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
