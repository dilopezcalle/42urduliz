/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:56:35 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/26 16:26:07 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	sa(t_list **stack_a)
{
	t_list	*aux;

	if (*stack_a == 0 || (*stack_a)->next == 0)
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = (*stack_a)->next;
	(*stack_a)->next = aux;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	t_list	*aux;

	if (*stack_b == 0 || (*stack_b)->next == 0)
		return ;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = (*stack_b)->next;
	(*stack_b)->next = aux;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sb(stack_a);
	sb(stack_b);
}
