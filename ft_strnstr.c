/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 08:27:53 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/15 15:39:05 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	size;
	size_t			i;

	i = -1;
	size = ft_strlen(needle);
	if (size == 0)
		return ((char *)haystack);
	if (size < len)
	{
		if (len > 2)
			if (ft_memchr(haystack, needle[0], len - 3) == NULL)
				return (NULL);
		if (ft_memchr(haystack, needle[0], len) == NULL)
			return (NULL);
		while (++i < len)
		{
			if (ft_strncmp(needle, ft_memchr(haystack + i, needle[0], len),
					size) == 0)
				return (ft_strchr(haystack + i, needle[0]));
			len--;
		}
	}
	if (ft_strncmp(haystack, needle, size) == 0)
		return ((char *)haystack);
	return (NULL);
}
/*
int	main(void)
{
	char	haystack[] = "lorem ipsum dolor sit amet";
	char	needle[] = "dolor";

	printf("Original function: %s\n", strnstr(haystack, needle, 15));
	printf("My function: %s\n", ft_strnstr(haystack, needle, 15));
	return (0);
}
*/
