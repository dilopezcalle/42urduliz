/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:53:22 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/07 14:31:50 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd_buffer_size(int fd, char *str, int *exit)
{
	char	*buffer;
	char	*aux;
	size_t	bytes_read;

	aux = ft_strjoin(str, "");
	if (!fd || fd == -1)
	{
		free(aux);
		return (NULL);
	}
	while (*exit == 0 && ft_strnl(aux) == -1)
	{
		buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
		{
			free(buffer);
			free(aux);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!aux && buffer[0] != '\n' && (int)bytes_read <= 0)
		{
			free(buffer);
			free(aux);
			return (NULL);
		}
		if(bytes_read != BUFFER_SIZE || buffer[0] == '\n')
			*exit = 1;
		if (!aux)
			aux = ft_substr(buffer, 0, BUFFER_SIZE);  
		else
			aux = ft_strjoin(aux, buffer);
		free(buffer);
	}
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*aux;
	static char	*str;
	int			exit;
	int			index;

	exit = 0;
	if (!str || ft_strnl(str) == -1)
	{
		aux = read_fd_buffer_size(fd, str, &exit);
		if (!aux)
		{
			free(aux);
			return (NULL);
		}
	}
	else
		aux = ft_strjoin(str, "");
	index = ft_strnl(aux) + 1;
	if (index == -1)
		index = ft_strlen(aux) - 1;
	str = ft_substr(aux, index, ft_strlen(aux));
	line = ft_substr(aux, 0, index);
	if (exit == 1 && str[0] == '\0')
		free(str);
	free(aux);
	/*
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	*/
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int	fd = open("./nl", O_RDONLY);
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
