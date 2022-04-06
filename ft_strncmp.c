/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:13:15 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/04 20:54:56 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while ((s1[i] || s2[i]) && n > 0 && result == 0)
	{
		if (s1[i] > s2[i])
			result = 1;
		else if (s1[i] < s2[i])
			result = -1;
		n--;
		i++;
	}
	return (result);
}

int	main(void)
{
	char	s1[] = "";
	char	s2[] = "";
	size_t	n = 2;

	printf("Original function: %d\n", strncmp(s1, s2, n));
	printf("My function: %d\n", ft_strncmp(s1, s2, n));
	return (0);
}

