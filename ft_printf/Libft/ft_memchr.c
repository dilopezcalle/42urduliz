/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 07:32:27 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/18 14:38:22 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;	

	str = (unsigned char *)s;
	i = 0;
	while ((unsigned int)i < (unsigned int)n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "";

	printf("Original function: %s\n", memchr(s, 2, 3));
	printf("My function: %s\n", ft_memchr(s, 2, 3));
	printf("size: %d\n". ft_strlen())
	return (0);
}
*/
