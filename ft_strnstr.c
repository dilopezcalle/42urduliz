/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 08:27:53 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/19 10:19:44 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	num;

	j = 0;
	i = 0;
	num = 0;
	while (to_find[num])
		num++;
	if (num == 0)
		return ((char *)&str[0]);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[j])
		{
			while (str[j + i] == to_find[j] && to_find[j] && n > i + j)
				j++;
			if (j == num)
				return ((char *)&str[i]);
		}
		j = 0;
		i++;
	}
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
