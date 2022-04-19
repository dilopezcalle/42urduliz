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
	char		*str;
	size_t		index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len <= 0)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	index = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (s[start] && index < len)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
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
