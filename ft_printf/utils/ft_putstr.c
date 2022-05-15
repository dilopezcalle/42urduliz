/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:54:40 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/15 13:51:51 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	bytes;
	int	i;

	i = 0;
	bytes = 0;
	if (!str)
		return (ft_putnull());
	while (str[i])
	{
		bytes += ft_putchar(str[i]);
		i++;
	}
	return (bytes);
}
