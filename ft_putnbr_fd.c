/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:29:27 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/18 11:03:39 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_count_numbers(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n = -n;
	}
	while (n > 9)
	{
		counter++;
		n = n / 10;
	}
	counter++;
	return (counter);
}

int	ft_putnbr_exp(int length)
{
	int	exp;

	exp = 1;
	length--;
	while (length > 0)
	{
		exp = exp * 10;
		length--;
	}
	return (exp);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	len;
	int	i;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	i = 0;
	len = ft_putnbr_count_numbers(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		i++;
		len--;
	}
	while (len > 0)
	{
		ft_putchar_fd((n / ft_putnbr_exp(len)) + '0', fd);
		n = n % ft_putnbr_exp(len);
		i++;
		len--;
	}
}
/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDWR | O_CREAT);
	ft_putnbr_fd(42, fd);
	return (0);
}
*/
