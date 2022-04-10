/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:13:55 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/10 17:55:25 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	int				size;

	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	if (!ft_strchr(s, (unsigned char)c))
		return (NULL);
	chr = c;
	size = ft_strlen(s) - 1;
	while (s[size])
	{
		if ((unsigned char)s[size] == chr)
			return ((char *)s + size);
		size--;
	}
	return (NULL);
}
/*
int main(void)
{
	char	s[] = "ltripouiel";

	printf("Original function: %s\n", strrchr(s, 'z'));
	printf("My function: %s\n", ft_strrchr(s, 'z'));
	return (0);
}
*/
