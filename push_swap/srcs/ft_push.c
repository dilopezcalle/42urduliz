/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:40:04 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/26 16:33:08 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (*stack_a == 0)
		return ;
	aux = *stack_a;
	*stack_a = (*stack_a)->next;
	aux->next = *stack_b;
	*stack_b = aux;
	write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*aux;

	if (*stack_b == 0)
		return ;
	aux = *stack_b;
	*stack_b = (*stack_b)->next;
	aux->next = *stack_a;
	*stack_a = aux;
	write(1, "pa\n", 3);
}
