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

int	ft_printf(char const *str, ...)
{
	int			i;
	va_list		vl;
	char	*s;

	i = 0;
	va_start(vl, str);
	s = va_arg(vl, char*);
	printf("%s\n", s);
	return (0);
}

int	main(void)
{
	//printf("Org: %c\n", 'a');
	ft_printf("Mio: %c\n", 'a');
	return (0);
}
