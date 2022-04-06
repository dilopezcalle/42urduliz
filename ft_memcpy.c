/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 08:20:11 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/02 11:57:42 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dst);
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
