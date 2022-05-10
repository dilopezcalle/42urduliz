/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:27:10 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/08 13:30:14 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	bytes;
	int	i;

	
	i = 0;
	bytes = 0;
	if (sizeof(str) == sizeof(char*))
		printf("Bieeeen\n");
	/*
	while (str[i])
	{
		bytes += ft_putchar(str[i]);
		i++;
	}
	*/
	return (bytes);
}

int	ft_printf(char const *format, ...)
{
	int			i;
	va_list		vl;
	char	*s;
	int	count_bytes;

	i = 0;
	count_bytes = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if(format[i + 1] == 'c')
				count_bytes += ft_putchar(va_arg(vl, int));
			if (format[i + 1] == 's')
				count_bytes += ft_putstr(va_arg(vl, char*));
			i += 2;

		}
		else if (format[i])
		{
			count_bytes += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(vl);
	return (count_bytes);
}

int	main(void)
{
	int org;
	int mio;

	//org = printf("Org: %s\n", 42);
	//printf("org: %d\n", org);
	mio = ft_printf("Mio: %s a %s\n", "hola", 'a');
	printf("mio: %d\n", mio);
	return (0);
}
