/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 07:35:14 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/10 17:20:16 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		result;
	result = 0;
	i = 0;
	while (i < n && result == 0)
	{
		result = ft_strncmp(s1 + i, s2 + i, 1);
		i++;
	}
	return (result);
}
/*
int	main(void)
{
	char	s1[] = "abcdefghij";
	char	s2[] = "abcdefgxyz";

	printf("Original function: %d\n", memcmp(s1, s2, 7));
	printf("My function: %d\n", ft_memcmp(s1, s2, 7));
	return (0);
}
*/
