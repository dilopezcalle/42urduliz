/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:27:10 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/14 22:04:58 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(char *str)
{
	return (printf("%p\n", str));
}

int	ft_printf(char const *format, ...)
{
	va_list		vl;
	int			count_bytes;
	int			i;

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
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				count_bytes += ft_putnbr_base(va_arg(vl, int), "0123456789");
			if (format[i + 1] == 'p')
				count_bytes += ft_putstr(va_arg(vl, char*));
			/*
			if (format[i + 1] == 'p')
				count_bytes += ft_putptr(va_arg(vl, void*));
			*/
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
	//char	*str = "hola";
	int 	org;
	int 	mio;

	org = printf("Org: %u\n", -1);
	printf("bytes: %d\n", org);
	mio = ft_printf("Mio: %d\n", -1);
	printf("bytes: %d\n", mio);
	return (0);
}

