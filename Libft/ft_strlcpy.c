/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:27:08 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/20 11:48:18 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > ft_strlen(src))
	{
		ft_bzero(dst, ft_strlen(src));
		ft_memmove(dst, src, ft_strlen(src));
		dst[ft_strlen(src)] = '\0';
	}
	else
	{
		ft_bzero(dst, dstsize);
		ft_memmove(dst, src, dstsize);
		dst[dstsize - 1] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	dst[15] = "aaaaaaaaaaaaaaa";
	char	dst2[15] = "aaaaaaaaaaaaaaa";
	char	src[] = "lorem ipsum dolor sit amet";
	size_t		result;

	result = 0;
	result = strlcpy(dst2, src, 0);
	printf("Original function: %zu	%s\n", result, dst2);
	write(1, dst2, 15);
	write(1, "\n", 1);

	result = ft_strlcpy(dst, src, 0);
	printf("My function: %zu	%s\n", result, dst);
	write(1, dst, 15);
	write(1, "\n", 1);
	return (0);
}
*/
