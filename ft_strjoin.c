/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:48:15 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/17 15:21:20 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(size + 1, 1);
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size + 1);
	return (str);
}
/*
int	main(void)
{
	char	*str;

	str = ft_strjoin("hola ", "buenas");
	printf("String: %s\n", str);
	free(str);
	return (0);
}
*/
