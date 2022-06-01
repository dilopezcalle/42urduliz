/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:34:42 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/31 08:19:47 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

void	ft_sort_3(t_list **stack_a)
{
	if ((*stack_a)->number < ((*stack_a)->next)->number)
	{
		if ((*stack_a)->number < (((*stack_a)->next)->next)->number)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
	else
	{
		if ((*stack_a)->number > (((*stack_a)->next)->next)->number)
		{
			if (((*stack_a)->next)->number > (((*stack_a)->next)->next)->number)
			{
				sa(stack_a);
				rra(stack_a);
			}
			else
				ra(stack_a);
		}
		else
			sa(stack_a);
	}
}
