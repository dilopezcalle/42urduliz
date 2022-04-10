/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:07:38 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/10 11:05:00 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	**str;

	str = NULL;	
	size = 0;
	if ((str = (unsigned char **)malloc(count)) == NULL)
		return (NULL);
	while (count > 0)
	{
		if ((str[count - 1] = (unsigned char *)malloc(size)) == NULL)
			return (NULL);
		count--;
	} 
	return (str);
}
/*
int	main(void)
{
	char	**str1;
	char	**str2;

	str2 = calloc(30, 1);
	str1 = ft_calloc(30, 1);

	str1[0] = "hola";
	str2[0] = "hl";
	write(1, str1, 30);
	write(1, "\n", 1);
	write(1, str2, 30);
	free(str2);
	free(str1);
	return (0);
}
*/
