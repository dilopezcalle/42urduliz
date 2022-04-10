/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:49:26 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/10 13:11:48 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		size;

	size = ft_strlen(s1);
	str = (char *) ft_calloc(size + 1, 1);
	if (str == NULL)
		return (NULL);
	return ((char *)ft_memmove(str, s1, size));
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;

	str2 = strdup("hola");
	str1 = ft_strdup("hola");
	printf("Original function: %s\n", str2);
	printf("My function: %s\n", str1);
	return (0);
}
*/
