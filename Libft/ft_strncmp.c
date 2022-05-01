/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:13:15 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/17 13:46:23 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && n > 0)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		n--;
		i++;
	}
	if (s1[i] != '\0' && s2[i] == '\0' && n > 0)
		return (1);
	else if (s1[i] == '\0' && s2[i] != '\0' && n > 0)
		return (-1);
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "\x12\xff\x65\x12\xbd\xde\xad";
	char	s2[] = "\x12\x02";
	size_t	n = 6;

	printf("Original function: %d\n", strncmp(s1, s2, n));
	printf("My function: %d\n", ft_strncmp(s1, s2, n));
	return (0);
}
*/
