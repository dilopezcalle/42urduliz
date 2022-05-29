/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:15 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/29 17:47:48 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_list	*ft_get_int_list(char *argv[])
{
	t_list		*stack_a;
	int			invalid;
	int			i;

	stack_a = ft_calloc(1, sizeof(t_list));
	if (stack_a == 0)
		exit(2);
	i = 0;
	invalid = 0;
	while (argv[i])
	{
		invalid = ft_create_list(argv[i], &stack_a, i);
		if (invalid == 1)
			ft_exit_program(stack_a, 0, 2);
		i++;
	}
	return (stack_a);
}

int	ft_create_list(char *argv, t_list **stack_a, int i)
{
	int		invalid;
	char	**str;
	int		j;

	invalid = 0;
	j = 0;
	str = ft_split(argv, ' ');
	while (str[j])
	{
		if (invalid == 0)
			invalid = ft_check_alpha(str[j]);
		if (invalid == 0)
			invalid = ft_add_list(*stack_a, str[j], i + j);
		free(str[j]);
		j++;
	}
	free(str);
	return (invalid);
}

int	ft_check_alpha(char *str)
{
	int		invalid;
	int		i;
	char	c;

	i = 0;
	invalid = 0;
	if (str[0] == '-')
		i++;
	while (str[i] && invalid == 0)
	{
		c = str[i];
		if (c < '0' || c > '9')
			invalid = 1;
		i++;
	}
	return (invalid);
}

int	ft_add_list(t_list *stack_a, char *str, int index)
{
	int		num;
	t_list	*new;

	num = ft_atoi(str);
	if (stack_a->number == num && index != 0)
		return (1);
	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (1);
	new->number = num;
	new->next = 0;
	if (ft_check_repeat(&stack_a, new, num) == 1)
		return (1);
	if (index == 0)
	{
		stack_a->number = new->number;
		free(new);
	}
	else
		stack_a->next = new;
	return (0);
}

int	ft_check_repeat(t_list **stack_a, t_list *new, int num)
{
	while ((*stack_a)->next != 0)
	{
		if ((*stack_a)->number == num || ((*stack_a)->next)->number == num)
		{
			free(new);
			return (1);
		}
		*stack_a = (*stack_a)->next;
	}
	return (0);
}
