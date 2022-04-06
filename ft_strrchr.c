/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:13:55 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/04 20:11:41 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = ft_strlen(s) - 1;
	if ((c == '\0' && size < 0) || s[0] == c)
		return ((char *)s);
	if (c == '\0')
		return (&((char *)s)[size + 1]);
	while (s[size] && s[size] != c && size > 0)
		size--;
	if (size <= 0)
		return (NULL);
	return (&((char *)s)[size]);
}
/*
int main(void)
{
	char	s[] = "bonjour";

	printf("Original function: %s\n", strrchr(s, 's'));
	printf("My function: %s\n", ft_strrchr(s, 's'));
	return (0);
}
*/
