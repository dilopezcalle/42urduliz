/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:27:10 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/15 16:05:55 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_check_format(char c, va_list vl)
{
	int	count_bytes;

	count_bytes = 0;
	if (c == 'c')
		count_bytes += ft_putchar(va_arg(vl, int));
	if (c == 's')
		count_bytes += ft_putstr(va_arg(vl, char *));
	if (c == 'p')
		count_bytes += ft_putptr(va_arg(vl, unsigned long int));
	if (c == 'd' || c == 'i')
		count_bytes += ft_putnbr_base(va_arg(vl, int), "0123456789");
	if (c == 'u')
		count_bytes += ft_putunsigned_base \
			(va_arg(vl, unsigned int), "0123456789");
	if (c == 'x')
		count_bytes += ft_putunsigned_base \
			(va_arg(vl, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count_bytes += ft_putunsigned_base \
			(va_arg(vl, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		count_bytes += ft_putchar('%');
	return (count_bytes);
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
			count_bytes += ft_check_format(format[i + 1], vl);
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
/*
int	main(void)
{
	//char	*str = "hola";
	int 	org;
	int 	mio;

	org = printf("Org: %p\n", (void *)-14523);
	printf("bytes: %d\n", org);
	mio = ft_printf("Mio: %p\n", (void *)-14523);
	printf("bytes: %d\n", mio);
	return (0);
}
*/
