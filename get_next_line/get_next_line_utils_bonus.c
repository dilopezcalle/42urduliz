/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:20:31 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/08 10:49:08 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = -1;
	str = (void *)malloc(count * size);
	if (str == NULL)
		return (NULL);
	while (++i < (count * size))
		((unsigned char *)str)[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	size;
	int				i;
	int				j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[size] = '\0';
	free(s1);
	return (str);
}

int	ft_strnl(const char *s)
{
	int	i;
	int	find;

	i = 0;
	if (!s || s[0] == '\0')
		return (-1);
	if ((char)s[0] == '\n')
		return (-2);
	while (s[i] && (char)s[i] != '\n')
	{
		if ((char)s[i] != '\n')
			find = 1;
		i++;
	}
	if (s[i] == '\0')
		return (-1);
	if (find == 1)
		return (++i);
	else
		return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		index;

	if (!s)
		return (NULL);
	if ((int)len == -2)
		len = 1;
	if ((int) start == -2)
		start = 1;
	if (start >= ft_strlen(s) || len <= 0)
		return (NULL);
	index = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (s[start] && index < len)
	{
		str[index] = s[start];
		index++;
		start++;
	}
	str[index] = '\0';
	return (str);
}
