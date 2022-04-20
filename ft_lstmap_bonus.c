/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:37:20 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/20 11:34:08 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final_lst;
	t_list	*aux;

	if (!lst && !*del && !*f)
		return (NULL);
	final_lst = NULL;
	while (lst)
	{
		aux = ft_lstnew((*f)(lst->content));
		ft_lstadd_back(&final_lst, aux);
		lst = lst->next;
	}
	return (final_lst);
}
/*
int	main(void)
{
	return (0);
}
*/
