/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:24:06 by dilopez-          #+#    #+#             */
/*   Updated: 2022/06/11 08:16:36 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)s[0] == (char)c)
		return ((char *)s);
	while (s[i] && (char)s[i] != (char)c)
		i++;
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	if (s[i] == '\0')
		return (NULL);
	return (&((char *)s)[i]);
}
