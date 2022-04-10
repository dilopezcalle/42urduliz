/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 08:27:53 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/10 13:16:13 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;

	size = ft_strlen(needle);
	if (size > 0 && ft_strncmp(haystack, "", 1) == 0)
		return (NULL);
	if (size == 0)
		return ((char *)haystack);
	if (size < len)
	{
		if (ft_memchr(haystack, needle[0], len - size + 1) == NULL)
			return (NULL);
		if (ft_strncmp(needle, ft_memchr(haystack, needle[0], len), size) == 0)
			return (ft_strchr(haystack, needle[0]));
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

	printf("Original function: %s\n", strnstr(haystack, needle, 16));
	printf("My function: %s\n", ft_strnstr(haystack, needle, 16));
	return (0);
}
*/
