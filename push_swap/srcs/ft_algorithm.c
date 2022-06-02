/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:22:11 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/02 10:25:29 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_algorithm(t_list **stack_a, t_list **stack_b, int size)
{
	int	num_bits;
	int	position;
	int	loop_size;

	num_bits = ft_get_bits(size);
	position = 0;
	while (position < num_bits)
	{
		loop_size = size;
		while (--loop_size >= 0)
		{
			if (((*stack_a)->index >> position) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		position++;
	}
}

int	ft_get_bits(int size)
{
	int	i;

	i = 0;
	size--;
	while (size > 0)
	{
		size = size / 2;
		i++;
	}
	return (i);
}
