/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:03:54 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/19 17:57:51 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	last_list = ft_lstlast(*lst);
	if (*lst == NULL)
		*lst = new;
	else
	{
		if (last_list == NULL)
			return ;
		last_list->next = new;
	}
}
/*
int	main(void)
{
	t_list	*list = NULL;
	t_list	*el_1;
	t_list	*el_2;

	

	ft_lstadd_front(&list, el_1);
	ft_lstadd_front(&list, el_2);
	return (0);
}
*/
