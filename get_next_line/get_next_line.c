/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:10:03 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/08 09:44:26 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
