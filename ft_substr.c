/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:38:10 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/18 10:22:25 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	size;
	unsigned int	max;
	unsigned int	i;

	i = 0;
	max = len + 1;
	size = ft_strlen(s);
	if (max < size)
		sub = (char *)ft_calloc(max, 1);
	else
		sub = (char *)ft_calloc(size + 1, 1);
	if (sub == NULL)
		return (NULL);
	if (start < size)
	{
		while (s[start] && i < max - 1)
		{
			sub[i] = s[start];
			start++;
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	s[] = "lorem ipsum dolor sit amet";
	char	*sub;
	
	sub = ft_substr(s, 400, 20);
	printf("Substring:\n");
	write(1, sub, 26);
	write(1, "\n", 1);
	free(sub);
	return (0);
}
*/
