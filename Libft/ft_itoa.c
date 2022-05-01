/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:07:59 by dilopez-          #+#    #+#             */
/*   Updated: 2022/04/19 11:28:45 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_count_numbers(int n)
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

int	ft_itoa_exp(int length)
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

char	*ft_itoa_write_str(char *str, int n, int length)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i++;
		length--;
	}
	while (length > 0)
	{
		str[i] = (n / ft_itoa_exp(length)) + '0';
		n = n % ft_itoa_exp(length);
		i++;
		length--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		i;

	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	i = 0;
	length = ft_itoa_count_numbers(n);
	str = (char *)ft_calloc(length + 1, 1);
	if (!str)
		return (NULL);
	return (ft_itoa_write_str(str, n, length));
}
/*
int	main(void)
{
	char	*str;

	str = ft_itoa(2147483647);
	printf("Numero transformado: %s\n", str);
//	printf("Cantidad de números: %d\n", ft_itoa_count_numbers(122));
//	printf("Los ceros: %d\n", ft_itoa_exp(3));
	free(str);
	return (0);
}
*/
