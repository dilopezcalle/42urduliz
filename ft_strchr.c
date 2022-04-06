/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:24:06 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/04 18:39:40 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (c == '\0')
		return (&((char *)s)[i]);
	if (s[i] == '\0')
		return (NULL);
	return (&((char *)s)[i]);
}
/*
int	main(void)
{
	char	s[10] = "hola";

	printf("Original function: %s\n", strchr(s, '\0'));
	printf("My function: %s\n", ft_strchr(s, '\0'));
	return (0);
}
*/
