/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:58:05 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/26 16:33:05 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_list));
	stack_b = 0;
	if (argc == 1)
		return (0);
	if (argc > 1)
	{
		stack_a = ft_get_int_list(argv + 1);
		/*
		while (stack_a != 0)
		{
			printf("%d ", stack_a->number);
			stack_a = stack_a->next;
		}
		*/
		//ss(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		//pa(&stack_a, &stack_b);

		while (stack_a != 0)
		{
			printf("%d ", stack_a->number);
			stack_a = stack_a->next;
		}
		printf("\n");
		while (stack_b != 0)
		{
			printf("%d ", stack_b->number);
			stack_b = stack_b->next;
		}

		
		printf("\n");
	}
	return (0);
}
