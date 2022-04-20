/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:03:40 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/18 12:02:35 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			size;
	unsigned char	sizedst;

	size = ft_strlen(dst);
	sizedst = dstsize;
	if (sizedst > size)
	{
		ft_strlcpy(dst + size, src, sizedst - size);
	}
	if (sizedst >= size)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + sizedst);
}
/*
#include <stdio.h>

int	main(void)
{
	
//	char dst[] = "pqrs"; //memset(dst, 'C', 5);
//	char dst2[] = "pqrs"; //memset(dst2, 'C', 5);
//	char	src[] = "abcdefghi";
	
	unsigned long	len;

	len = 6;
	
	//memset(dst, 0, 15);
	//memset(dst, 'r', 6);

	//memset(dst2, 0, 15);
	//memset(dst2, 'r', 6);
	

//	printf("Original function: %lu	", strlcat("pqrs", "abcdefghi", 15));
//	write(1, dst2, 15);
//	write(1, "\n", 1);

//	printf("My function: %lu	", ft_strlcat(dst, src, 15));
	printf("Original function: %lu	", ft_strlcat("pqrs", "abcdefghi", 15));
//	write(1, dst, 15);
//	write(1, "\n", 1);
//	printf("%s\n", dst);

	return (0);
}
*/
