/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:56:09 by dilopez-          #+#    #+#             */
/*   Updated: 2022/05/15 15:28:16 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	ft_putunsigned_base(unsigned long int nbr, char *base)
{
	int		i;
	int		size;
	int		bytes;
	char	str_nbr[18];

	i = 0;
	size = 0;
	bytes = 0;
	while (base[size] != '\0')
		size++;
	ft_unsigned_generate_str(str_nbr, base, nbr, size);
	ft_rev_string(str_nbr);
	while (str_nbr[i] != '\0')
	{
		bytes += write(1, &str_nbr[i], 1);
		i++;
	}
	return (bytes);
}

void	ft_unsigned_generate_str(char *str_nbr, \
		char *base, unsigned long int nbr, int size)
{
	unsigned long int	nbr_loop;
	int					i;

	i = 0;
	nbr_loop = nbr;
	if (nbr < 0)
		nbr_loop = -nbr_loop;
	while (nbr_loop > 0)
	{
		str_nbr[i] = base[nbr_loop % size];
		nbr_loop = nbr_loop / size;
		i++;
	}
	if (nbr <= 0)
	{
		if (nbr < 0)
			str_nbr[i] = '-';
		else
			str_nbr[i] = '0';
		i++;
	}
	str_nbr[i] = '\0';
}
