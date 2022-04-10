/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:03:40 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/10 18:24:29 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;
	unsigned char	sizedst;

	size = ft_strlen(dst);
	sizedst = dstsize;
	if (sizedst > size)
	{
		ft_memmove(dst + size, src, sizedst - size);
		if (sizedst > ft_strlen(dst))
			dst[ft_strlen(dst)] = '\0';
		else
			dst[ft_strlen(dst) - 1] = '\0';
	}
	if (dstsize >= size)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + sizedst);
}

int	main(void)
{
	char dst[30]; memset(dst, 0, 30);
	char dst2[30]; memset(dst, 0, 30);
	char	src[] = "AAAAAAAAA";
	unsigned long	len;

	len = 30;

	printf("Original function: %lu	", strlcat(dst2, src, len));
	write(1, dst2, 10);
	write(1, "\n", 1);

	printf("My function: %lu	", ft_strlcat(dst, src, len));
	write(1, dst, 10);
	write(1, "\n", 1);
	

	return (0);
}

