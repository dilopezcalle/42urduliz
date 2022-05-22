/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:15 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/22 18:14:28 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	ft_get_int_list(char *argv[])
{
	t_list		*stack_a;
	char		**str;
	int			invalid;
	int			i;
	int			j;

	stack_a = ft_calloc(1, sizeof(t_list));
	if (stack_a == 0)
		exit(2);
	i = 0;
	invalid = 0;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			if (invalid == 0)
				invalid = ft_check_alpha(str[j]);
			if (invalid == 0)
				invalid = ft_add_list(stack_a, str[j], i + j);
			free(str[j]);
			j++;
		}
		free(str);
		if (invalid == 1)
			ft_exit_program(stack_a, 0, 1);
		i++;
	}
	ft_exit_program(stack_a, 0, 0);
	return (0);
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
	int		unordered;

	num = ft_atoi(str);
	new = ft_calloc(1, sizeof(t_list));
	if (!new)
		return (1);
	new->number = num;
	new->next = 0;
	unordered = 1;
	while (stack_a->next != 0)
	{
		if (stack_a->number <= num || (stack_a->next)->number == num)
		{
			free(new);
			return (1);
		}
		if 
		stack_a = stack_a->next;
	}
	if (index == 0)
	{
		stack_a->number = new->number;
		free(new);
	}
	else
		stack_a->next = new;
	return (0);
}
