/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:03:40 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/03 18:33:36 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	size = ft_strlen(dst);
	if (dstsize > size)
	{
		ft_memmove(dst + size, src, dstsize - size);
		if (dstsize > ft_strlen(dst))
			dst[ft_strlen(dst)] = '\0';
		else
			dst[ft_strlen(dst) - 1] = '\0';
	}
	if (dstsize >= size)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + dstsize);
}
/*
int	main(void)
{
	char	dst[10] = "h\0ola";
	char	dst2[10] = "h\0ola";
	char	src[] = "buenas";
	unsigned long	len;

	len = 10;

	printf("Original function: %lu	", strlcat(dst2, src, len));
	write(1, dst2, 10);
	write(1, "\n", 1);

	printf("My function: %lu	", ft_strlcat(dst, src, len));
	write(1, dst, 10);
	write(1, "\n", 1);

	return (0);
}
*/
