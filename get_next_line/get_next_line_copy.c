/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:53:22 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/01 15:11:03 by dilopez-         ###   ########.fr       */
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
		return (NULL);
	while (ft_strnl(aux) == 0 && *exit == 0)
	{
		buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			printf("hola");
			return (NULL);
		}
		else if(bytes_read != BUFFER_SIZE)
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
	int		exit;

	exit = 0;
	if ((str && ft_strnl(str) == 0) || !str)
		aux = read_fd_buffer_size(fd, str, &exit);
	else
	{
		aux = ft_strjoin(str, "");
		exit = 1;
	}
	str = ft_substr(aux, ft_strnl(aux), ft_strlen(aux));
	line = ft_substr(aux, 0, ft_strnl(aux));
	if (exit == 1)
		free(str);
	free(aux);
	return (line);
}

int	main(void)
{
	char	*line;
	int	fd = open("./fichero", O_RDONLY);
	int	i;

	i = 0;
	
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("Linea: %s\n", line);
		free(line);
		i++;
	}
	return (0);
}
