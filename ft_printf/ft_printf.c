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

int	ft_printf(char const *str, ...)
{
	int			i;
	va_list		vl;
	char	*s;

	i = 0;
	va_start(vl, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if(str[i + 1] == 'c')
				ft_putchar(va_arg(vl, int));
			i += 2;
		}
		if (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(vl);	
	return (0);
}

int	main(void)
{
	//printf("Org: %c\n", 'a');
	ft_printf("Mio: %c\n", 'a');
	return (0);
}
