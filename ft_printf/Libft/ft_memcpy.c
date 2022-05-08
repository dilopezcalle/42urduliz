/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 08:20:11 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/20 11:47:41 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return ((unsigned char *)dst);
}
/*
//#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	dst[20] = "zy\0xw\0vu\0\0tsr";
	char	dst2[20] = "zy\0xw\0vu\0\0tsr";
//	char	src[10] = "";

	printf("Original function: %s\n", 
	memcpy(dst2, "aaa", 3));
	write(1, dst2, 20);
	printf("My function: %s\n", ft_memcpy(dst, 
	"aaa", 3));
	write(1, dst, 20);
	return (0);
}
*/
