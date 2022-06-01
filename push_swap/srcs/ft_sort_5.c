/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:18:14 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/01 15:39:01 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 3 && (*stack_a)->index != 4)
		ra(stack_a);
	pb(stack_a, stack_b);
	while ((*stack_a)->index != 3 && (*stack_a)->index != 4)
		ra(stack_a);
	pb(stack_a, stack_b);
	if ((*stack_b)->index < ((*stack_b)->next)->index)
		sb(stack_b);
	if (ft_issorted(stack_a) == 0)
		ft_sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
}
