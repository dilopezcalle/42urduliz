/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:43:55 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/19 15:09:50 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_list;

	if (!lst)
		return (NULL);
	last_list = lst;
	while (last_list->next != NULL)
		last_list = last_list->next;
	return (last_list);
}

/*
int	main(void)
{

	return (0);
}
*/
