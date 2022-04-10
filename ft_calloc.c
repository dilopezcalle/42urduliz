/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:07:20 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/10 18:06:08 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;

	if (size == 0 || count == 0 || count >= SIZE_MAX / size)
		return (NULL);
	str = (unsigned char *)malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', count * size);
	return (str);
}
/*
int	main(void)
{
	char	**str1;
//	char	**str2;

//	str2 = calloc(SIZE_MAX, SIZE_MAX);
	str1 = ft_calloc(4, 0);

	str1[0] = "hola";
//	str2[0] = "hl";
	write(1, str1, 30);
	write(1, "\n", 1);
//	write(1, str2, 30);
//	free(str2);
	free(str1);
	return (0);
}
*/
