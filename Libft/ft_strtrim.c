/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:23:45 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/18 10:23:02 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		trim_left;
	int		i;

	if (s1[0] == '\0')
		return ((char *)ft_calloc(1, 1));
	trim_left = 0;
	while (s1[trim_left] && ft_strchr(set, s1[trim_left]))
		trim_left++;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strrchr(set, s1[i]))
		i--;
	return (ft_substr(s1, trim_left, i - trim_left + 1));
}
/*
int	main(void)
{
	char	*str;

	str = ft_strtrim("lorem", " ");
	printf("String: %s\n", str);
	printf("Char: %c\n", str[6]);
	free (str);
	return (0);
}
*/
