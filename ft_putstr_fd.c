/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:16:14 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/18 10:24:36 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;
	
	fd = open("prueba.txt", O_RDWR | O_CREAT);
	ft_putstr_fd("hola", fd);
	return (0);
}
*/
