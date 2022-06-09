/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:07:20 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/06 08:10:13 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', count * size);
	return (str);
}
