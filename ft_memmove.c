/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:58:19 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/03 13:00:59 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	temp = (char *)malloc(len);
	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	free(temp);
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[10] = "";
	char	dst2[10] = "";
	char	src[] = "lorem ipsum dolor sit amet";

	printf("Original function: %s\n", memmove(dst2, src, 10));
	printf("My function: %s\n", ft_memmove(dst, src, 10));
	return (0);
}
*/
