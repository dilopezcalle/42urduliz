/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 07:01:09 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/28 08:46:16 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	ra(t_list **stack_a)
{
	t_list	*aux;

	if (*stack_a == 0 || (*stack_a)->next == 0)
		return ;
	aux = *stack_a;
	while ((*stack_a)->next != 0)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = aux;
	*stack_a = aux->next;
	aux->next = 0;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	t_list	*aux;

	if (*stack_b == 0 || (*stack_b)->next == 0)
		return ;
	aux = *stack_b;
	while ((*stack_b)->next != 0)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = aux;
	*stack_b = aux->next;
	aux->next = 0;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
