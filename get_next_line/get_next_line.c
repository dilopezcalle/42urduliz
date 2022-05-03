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

char	*read_fd_buffer_size(int fd, char *str)
{
	char	*buffer;
	char	*aux;
	size_t	bytes_read;

	if (!fd || fd == -1)
		return (NULL);
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	if (!str)
		str = ft_strjoin("", buffer);
	else
	{
		aux = ft_strjoin("", str);
		free(str);
		str = ft_strjoin(aux, buffer);
		free(aux);
	}
	free(buffer);
	if (ft_strnl(str) == 0)
		read_fd_buffer_size(fd, str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*aux;
	static char	*str;

	aux = read_fd_buffer_size(fd, str);
	if (str)
		free(str);
	str = ft_substr(aux, ft_strnl(aux), ft_strlen(aux));
	line = ft_substr(aux, 0, ft_strnl(aux));
	//printf("string: %s\n", str);
	free(str);
	free(aux);
	return (line);
}

int	main(void)
{
	char	*line;
	int	fd = open("./fichero", O_RDONLY);

	line = get_next_line(fd);
	//printf("%d\n", ft_strnl(line));
	//printf("Linea: %s\n", line);
	free(line);
	return (0);
}
