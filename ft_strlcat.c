/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:03:40 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/14 11:55:33 by dilopez-         ###   ########.fr       */
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
		ft_bzero(dst + ft_strlen(dst), 1);
	}
	if (sizedst >= size)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + sizedst);
}
/*
int	main(void)
{
	char dst[30] = "BBBB"; //memset(dst, 'C', 5);
	char dst2[30] = "BBBB"; //memset(dst2, 'C', 5);
	char	src[] = "AAAAAAAAA";
	unsigned long	len;

	len = 6;
	
	//memset(dst, 0, 15);
	//memset(dst, 'r', 6);

	//memset(dst2, 0, 15);
	//memset(dst2, 'r', 6);
	

	printf("Original function: %lu	", strlcat(dst2, src, len));
	write(1, dst2, 15);
	write(1, "\n", 1);

	printf("My function: %lu	", ft_strlcat(dst, src, len));
	write(1, dst, 15);
	write(1, "\n", 1);
	printf("%s\n", dst);	

	return (0);
}
*/
