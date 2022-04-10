/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:58:19 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/09 08:54:39 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)malloc(len);
	ft_memcpy(temp, (unsigned char *)src, len);
	ft_memcpy((unsigned char *)dst, temp, len);
	free(temp);
	return ((unsigned char *)dst);
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
