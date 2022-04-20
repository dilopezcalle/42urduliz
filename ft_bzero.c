/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 07:27:13 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/20 11:47:11 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
#include <stdio.h>
#include <unistd.h>
#include <strings.h>

int	main(void)
{
	char	s[] = "aaaaa";
	char	s2[] = "";

	bzero(s2, 2);
	write(1, s2, 6);
	write(1, "\n", 1);

	ft_bzero(s, 2);
	write(1, s, 6);
	write(1, "\n", 1);
	return (0);
}
*/
