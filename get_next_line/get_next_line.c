/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:10:03 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/08 09:15:35 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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



char	*get_next_line(int fd)
{
	static char	*str;
	char		*aux;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytes_read;
	
	bytes_read = BUFFER_SIZE;
	buffer[BUFFER_SIZE] = '\0';
	aux = ft_strjoin(str, "");
	str = NULL;
	if (!fd || fd == -1)
		return (NULL);
	while (bytes_read > 0 && ft_strnl(aux) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((int)bytes_read <= 0)
		{
			if ((int)bytes_read == 0)
				return (aux);
			free(aux);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!aux && bytes_read > 0)
			aux = ft_substr(buffer, 0, BUFFER_SIZE);
		else if (bytes_read > 0)
			aux = ft_strjoin(aux, buffer);
	}
	line = ft_substr(aux, 0, ft_strnl(aux));
	str = ft_substr(aux, ft_strnl(aux), ft_strlen(aux));
	if (bytes_read <= 0)
		free(str);
	free(aux);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int	fd = open("./multiple_nlx5", O_RDONLY);
	int	i;

	i = 0;
	
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("Linea: %s\n", line);
		free(line);
		i++;
	}
	return (0);
}
*/
